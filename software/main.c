#include <atmel_start.h>

#include "led.h"

/** RX activity led */
struct led rx_act_led = DEFAULT_LED_CONFIG;
/** TX activity led */
struct led tx_act_led = DEFAULT_LED_CONFIG;

/** CAN RX callback */
void can_rx_cb(struct can_async_descriptor* const descr);
/** CAN TX callback */
void can_tx_cb(struct can_async_descriptor* const descr);

/** Main entrypoint */
int main(void)
{
	struct can_filter filter;
	struct can_message msg;
	uint8_t msg_data[3];

	/* Initialize MCU, drivers and middleware */
	atmel_start_init();

	printf("hello world\r\n");

	/* Configure RX activity LED */
	rx_act_led.pin    = RX_ACT;
	rx_act_led.wiring = led_wired_active_low;
	register_led(&rx_act_led);
	/* Configure TX activity LED */
	tx_act_led.pin    = TX_ACT;
	tx_act_led.wiring = led_wired_active_low;
	register_led(&tx_act_led);

	/* Register CAN callbacks */
	can_async_register_callback(&CAN_0, CAN_ASYNC_RX_CB, (FUNC_PTR) can_rx_cb);
	can_async_register_callback(&CAN_0, CAN_ASYNC_TX_CB, (FUNC_PTR) can_tx_cb);

	/* Configure CAN filter 0 */
	filter.id   = 0x123;
	filter.mask = 0xFFFFFFFF;
	can_async_set_filter(&CAN_0, 0, CAN_FMT_STDID, &filter);

	/* Configure CAN filter 1 */
	filter.id   = 0x456;
	filter.mask = 0xFFFFFFFF;
	can_async_set_filter(&CAN_0, 1, CAN_FMT_STDID, &filter);

	/* Enable CAN peripheral */
	can_async_enable(&CAN_0);

	/* Enable transceiver */
	gpio_set_pin_level(CAN_EN, 1);
	gpio_set_pin_level(CAN_STB, 1);

	/* Wait for transceiver to enter normal mode */
	delay_ms(10);

	/* Prepare CAN message to send */
	msg.type = CAN_TYPE_DATA;
	msg.fmt  = CAN_FMT_STDID;
	msg.id   = 0x123;
	msg.len  = 3;
	msg.data = msg_data;
	msg_data[0] = 0xAA;
	msg_data[1] = 0xAA;
	msg_data[2] = 0xAA;

	for (unsigned int cycle = 0;; cycle++)
	{
		/* Call LED driver */
		led_cycle();

		/* Send CAN message every 1s */
		if (cycle % 1000 == 0)
		{
			printf("sending message now\r\n");

			msg_data[0] = cycle & 0xff;
			msg_data[1] = 0x42;
			msg_data[2] = 0x69;
			can_async_write(&CAN_0, &msg);
		}

		/* 1 cycle == 1ms */
		delay_ms(1);
	}
}

void can_rx_cb(struct can_async_descriptor* const descr)
{
	struct can_message msg;
	uint8_t msg_data[64];
	msg.data = msg_data;

	/* Read received message */
	can_async_read(descr, &msg);

	/* Print received message */
	printf("can %8lx %2d", msg.id, msg.len);
	for (int i = 0; i < msg.len; i++)
	{
		printf(" %02x", msg_data[i]);
	}
	printf("\r\n");

	/* Flash RX activity LED */
	flash_led(&rx_act_led);
}

void can_tx_cb(struct can_async_descriptor* const descr)
{
	(void) descr;

	/* Flash TX activity LED */
	flash_led(&tx_act_led);
}
