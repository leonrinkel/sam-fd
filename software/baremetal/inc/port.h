#ifndef SAMFD_PORT_H
#define SAMFD_PORT_H

#include <stdint.h>

/** \brief PORT registers base address */
#define PORT_ADDR 0x41000000u

/** \name PORT DIR register */
/**@{*/

/** \brief PORT DIR register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Port data direction for pin 0 */
		uint32_t DIR0:1;
		/** \brief Port data direction for pin 1 */
		uint32_t DIR1:1;
		/** \brief Port data direction for pin 2 */
		uint32_t DIR2:1;
		/** \brief Port data direction for pin 3 */
		uint32_t DIR3:1;
		/** \brief Port data direction for pin 4 */
		uint32_t DIR4:1;
		/** \brief Port data direction for pin 5 */
		uint32_t DIR5:1;
		/** \brief Port data direction for pin 6 */
		uint32_t DIR6:1;
		/** \brief Port data direction for pin 7 */
		uint32_t DIR7:1;
		/** \brief Port data direction for pin 8 */
		uint32_t DIR8:1;
		/** \brief Port data direction for pin 9 */
		uint32_t DIR9:1;
		/** \brief Port data direction for pin 10 */
		uint32_t DIR10:1;
		/** \brief Port data direction for pin 11 */
		uint32_t DIR11:1;
		/** \brief Port data direction for pin 12 */
		uint32_t DIR12:1;
		/** \brief Port data direction for pin 13 */
		uint32_t DIR13:1;
		/** \brief Port data direction for pin 14 */
		uint32_t DIR14:1;
		/** \brief Port data direction for pin 15 */
		uint32_t DIR15:1;
		/** \brief Port data direction for pin 16 */
		uint32_t DIR16:1;
		/** \brief Port data direction for pin 17 */
		uint32_t DIR17:1;
		/** \brief Port data direction for pin 18 */
		uint32_t DIR18:1;
		/** \brief Port data direction for pin 19 */
		uint32_t DIR19:1;
		/** \brief Port data direction for pin 20 */
		uint32_t DIR20:1;
		/** \brief Port data direction for pin 21 */
		uint32_t DIR21:1;
		/** \brief Port data direction for pin 22 */
		uint32_t DIR22:1;
		/** \brief Port data direction for pin 23 */
		uint32_t DIR23:1;
		/** \brief Port data direction for pin 24 */
		uint32_t DIR24:1;
		/** \brief Port data direction for pin 25 */
		uint32_t DIR25:1;
		/** \brief Port data direction for pin 26 */
		uint32_t DIR26:1;
		/** \brief Port data direction for pin 27 */
		uint32_t DIR27:1;
		/** \brief Port data direction for pin 28 */
		uint32_t DIR28:1;
		/** \brief Port data direction for pin 29 */
		uint32_t DIR29:1;
		/** \brief Port data direction for pin 30 */
		uint32_t DIR30:1;
		/** \brief Port data direction for pin 31 */
		uint32_t DIR31:1;
	} B;
} port_dir_t;

/** \brief PORT DIR register address offset */
#define PORT_DIR_OFF 0x00u

/** \brief PORT DIR register address */
#define PORT_DIR_ADDR (PORT_ADDR + PORT_DIR_OFF)

/** \brief PORT DIR register */
#define PORT_DIR (*((volatile port_dir_t*) PORT_DIR_ADDR))

/** \brief PORT DIR.DIR0 bit offset */
#define PORT_DIR_DIR0_OFF 0u
/** \brief PORT DIR.DIR0 bit mask */
#define PORT_DIR_DIR0_MSK (0x1u << PORT_DIR_DIR0_OFF)

/** \brief PORT DIR.DIR1 bit offset */
#define PORT_DIR_DIR1_OFF 1u
/** \brief PORT DIR.DIR1 bit mask */
#define PORT_DIR_DIR1_MSK (0x1u << PORT_DIR_DIR1_OFF)

/** \brief PORT DIR.DIR2 bit offset */
#define PORT_DIR_DIR2_OFF 2u
/** \brief PORT DIR.DIR2 bit mask */
#define PORT_DIR_DIR2_MSK (0x1u << PORT_DIR_DIR2_OFF)

/** \brief PORT DIR.DIR3 bit offset */
#define PORT_DIR_DIR3_OFF 3u
/** \brief PORT DIR.DIR3 bit mask */
#define PORT_DIR_DIR3_MSK (0x1u << PORT_DIR_DIR3_OFF)

/** \brief PORT DIR.DIR4 bit offset */
#define PORT_DIR_DIR4_OFF 4u
/** \brief PORT DIR.DIR4 bit mask */
#define PORT_DIR_DIR4_MSK (0x1u << PORT_DIR_DIR4_OFF)

/** \brief PORT DIR.DIR5 bit offset */
#define PORT_DIR_DIR5_OFF 5u
/** \brief PORT DIR.DIR5 bit mask */
#define PORT_DIR_DIR5_MSK (0x1u << PORT_DIR_DIR5_OFF)

/** \brief PORT DIR.DIR6 bit offset */
#define PORT_DIR_DIR6_OFF 6u
/** \brief PORT DIR.DIR6 bit mask */
#define PORT_DIR_DIR6_MSK (0x1u << PORT_DIR_DIR6_OFF)

/** \brief PORT DIR.DIR7 bit offset */
#define PORT_DIR_DIR7_OFF 7u
/** \brief PORT DIR.DIR7 bit mask */
#define PORT_DIR_DIR7_MSK (0x1u << PORT_DIR_DIR7_OFF)

/** \brief PORT DIR.DIR8 bit offset */
#define PORT_DIR_DIR8_OFF 8u
/** \brief PORT DIR.DIR8 bit mask */
#define PORT_DIR_DIR8_MSK (0x1u << PORT_DIR_DIR8_OFF)

/** \brief PORT DIR.DIR9 bit offset */
#define PORT_DIR_DIR9_OFF 9u
/** \brief PORT DIR.DIR9 bit mask */
#define PORT_DIR_DIR9_MSK (0x1u << PORT_DIR_DIR9_OFF)

/** \brief PORT DIR.DIR10 bit offset */
#define PORT_DIR_DIR10_OFF 10u
/** \brief PORT DIR.DIR10 bit mask */
#define PORT_DIR_DIR10_MSK (0x1u << PORT_DIR_DIR10_OFF)

/** \brief PORT DIR.DIR11 bit offset */
#define PORT_DIR_DIR11_OFF 11u
/** \brief PORT DIR.DIR11 bit mask */
#define PORT_DIR_DIR11_MSK (0x1u << PORT_DIR_DIR11_OFF)

/** \brief PORT DIR.DIR12 bit offset */
#define PORT_DIR_DIR12_OFF 12u
/** \brief PORT DIR.DIR12 bit mask */
#define PORT_DIR_DIR12_MSK (0x1u << PORT_DIR_DIR12_OFF)

/** \brief PORT DIR.DIR13 bit offset */
#define PORT_DIR_DIR13_OFF 13u
/** \brief PORT DIR.DIR13 bit mask */
#define PORT_DIR_DIR13_MSK (0x1u << PORT_DIR_DIR13_OFF)

/** \brief PORT DIR.DIR14 bit offset */
#define PORT_DIR_DIR14_OFF 14u
/** \brief PORT DIR.DIR14 bit mask */
#define PORT_DIR_DIR14_MSK (0x1u << PORT_DIR_DIR14_OFF)

/** \brief PORT DIR.DIR15 bit offset */
#define PORT_DIR_DIR15_OFF 15u
/** \brief PORT DIR.DIR15 bit mask */
#define PORT_DIR_DIR15_MSK (0x1u << PORT_DIR_DIR15_OFF)

/** \brief PORT DIR.DIR16 bit offset */
#define PORT_DIR_DIR16_OFF 16u
/** \brief PORT DIR.DIR16 bit mask */
#define PORT_DIR_DIR16_MSK (0x1u << PORT_DIR_DIR16_OFF)

/** \brief PORT DIR.DIR17 bit offset */
#define PORT_DIR_DIR17_OFF 17u
/** \brief PORT DIR.DIR17 bit mask */
#define PORT_DIR_DIR17_MSK (0x1u << PORT_DIR_DIR17_OFF)

/** \brief PORT DIR.DIR18 bit offset */
#define PORT_DIR_DIR18_OFF 18u
/** \brief PORT DIR.DIR18 bit mask */
#define PORT_DIR_DIR18_MSK (0x1u << PORT_DIR_DIR18_OFF)

/** \brief PORT DIR.DIR19 bit offset */
#define PORT_DIR_DIR19_OFF 19u
/** \brief PORT DIR.DIR19 bit mask */
#define PORT_DIR_DIR19_MSK (0x1u << PORT_DIR_DIR19_OFF)

/** \brief PORT DIR.DIR20 bit offset */
#define PORT_DIR_DIR20_OFF 20u
/** \brief PORT DIR.DIR20 bit mask */
#define PORT_DIR_DIR20_MSK (0x1u << PORT_DIR_DIR20_OFF)

/** \brief PORT DIR.DIR21 bit offset */
#define PORT_DIR_DIR21_OFF 21u
/** \brief PORT DIR.DIR21 bit mask */
#define PORT_DIR_DIR21_MSK (0x1u << PORT_DIR_DIR21_OFF)

/** \brief PORT DIR.DIR22 bit offset */
#define PORT_DIR_DIR22_OFF 22u
/** \brief PORT DIR.DIR22 bit mask */
#define PORT_DIR_DIR22_MSK (0x1u << PORT_DIR_DIR22_OFF)

/** \brief PORT DIR.DIR23 bit offset */
#define PORT_DIR_DIR23_OFF 23u
/** \brief PORT DIR.DIR23 bit mask */
#define PORT_DIR_DIR23_MSK (0x1u << PORT_DIR_DIR23_OFF)

/** \brief PORT DIR.DIR24 bit offset */
#define PORT_DIR_DIR24_OFF 24u
/** \brief PORT DIR.DIR24 bit mask */
#define PORT_DIR_DIR24_MSK (0x1u << PORT_DIR_DIR24_OFF)

/** \brief PORT DIR.DIR25 bit offset */
#define PORT_DIR_DIR25_OFF 25u
/** \brief PORT DIR.DIR25 bit mask */
#define PORT_DIR_DIR25_MSK (0x1u << PORT_DIR_DIR25_OFF)

/** \brief PORT DIR.DIR26 bit offset */
#define PORT_DIR_DIR26_OFF 26u
/** \brief PORT DIR.DIR26 bit mask */
#define PORT_DIR_DIR26_MSK (0x1u << PORT_DIR_DIR26_OFF)

/** \brief PORT DIR.DIR27 bit offset */
#define PORT_DIR_DIR27_OFF 27u
/** \brief PORT DIR.DIR27 bit mask */
#define PORT_DIR_DIR27_MSK (0x1u << PORT_DIR_DIR27_OFF)

/** \brief PORT DIR.DIR28 bit offset */
#define PORT_DIR_DIR28_OFF 28u
/** \brief PORT DIR.DIR28 bit mask */
#define PORT_DIR_DIR28_MSK (0x1u << PORT_DIR_DIR28_OFF)

/** \brief PORT DIR.DIR29 bit offset */
#define PORT_DIR_DIR29_OFF 29u
/** \brief PORT DIR.DIR29 bit mask */
#define PORT_DIR_DIR29_MSK (0x1u << PORT_DIR_DIR29_OFF)

/** \brief PORT DIR.DIR30 bit offset */
#define PORT_DIR_DIR30_OFF 30u
/** \brief PORT DIR.DIR30 bit mask */
#define PORT_DIR_DIR30_MSK (0x1u << PORT_DIR_DIR30_OFF)

/** \brief PORT DIR.DIR31 bit offset */
#define PORT_DIR_DIR31_OFF 31u
/** \brief PORT DIR.DIR31 bit mask */
#define PORT_DIR_DIR31_MSK (0x1u << PORT_DIR_DIR31_OFF)

/**@}*/

/** \name PORT OUT register */
/**@{*/

/** \brief PORT OUT register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Port data output value for pin 0 */
		uint32_t OUT0:1;
		/** \brief Port data output value for pin 1 */
		uint32_t OUT1:1;
		/** \brief Port data output value for pin 2 */
		uint32_t OUT2:1;
		/** \brief Port data output value for pin 3 */
		uint32_t OUT3:1;
		/** \brief Port data output value for pin 4 */
		uint32_t OUT4:1;
		/** \brief Port data output value for pin 5 */
		uint32_t OUT5:1;
		/** \brief Port data output value for pin 6 */
		uint32_t OUT6:1;
		/** \brief Port data output value for pin 7 */
		uint32_t OUT7:1;
		/** \brief Port data output value for pin 8 */
		uint32_t OUT8:1;
		/** \brief Port data output value for pin 9 */
		uint32_t OUT9:1;
		/** \brief Port data output value for pin 10 */
		uint32_t OUT10:1;
		/** \brief Port data output value for pin 11 */
		uint32_t OUT11:1;
		/** \brief Port data output value for pin 12 */
		uint32_t OUT12:1;
		/** \brief Port data output value for pin 13 */
		uint32_t OUT13:1;
		/** \brief Port data output value for pin 14 */
		uint32_t OUT14:1;
		/** \brief Port data output value for pin 15 */
		uint32_t OUT15:1;
		/** \brief Port data output value for pin 16 */
		uint32_t OUT16:1;
		/** \brief Port data output value for pin 17 */
		uint32_t OUT17:1;
		/** \brief Port data output value for pin 18 */
		uint32_t OUT18:1;
		/** \brief Port data output value for pin 19 */
		uint32_t OUT19:1;
		/** \brief Port data output value for pin 20 */
		uint32_t OUT20:1;
		/** \brief Port data output value for pin 21 */
		uint32_t OUT21:1;
		/** \brief Port data output value for pin 22 */
		uint32_t OUT22:1;
		/** \brief Port data output value for pin 23 */
		uint32_t OUT23:1;
		/** \brief Port data output value for pin 24 */
		uint32_t OUT24:1;
		/** \brief Port data output value for pin 25 */
		uint32_t OUT25:1;
		/** \brief Port data output value for pin 26 */
		uint32_t OUT26:1;
		/** \brief Port data output value for pin 27 */
		uint32_t OUT27:1;
		/** \brief Port data output value for pin 28 */
		uint32_t OUT28:1;
		/** \brief Port data output value for pin 29 */
		uint32_t OUT29:1;
		/** \brief Port data output value for pin 30 */
		uint32_t OUT30:1;
		/** \brief Port data output value for pin 31 */
		uint32_t OUT31:1;
	} B;
} port_out_t;

/** \brief PORT OUT register address offset */
#define PORT_OUT_OFF 0x10u

/** \brief PORT OUT register address */
#define PORT_OUT_ADDR (PORT_ADDR + PORT_OUT_OFF)

/** \brief PORT OUT register */
#define PORT_OUT (*((volatile port_out_t*) PORT_OUT_ADDR))

/** \brief PORT OUT.OUT0 bit offset */
#define PORT_OUT_OUT0_OFF 0u
/** \brief PORT OUT.OUT0 bit mask */
#define PORT_OUT_OUT0_MSK (0x1u << PORT_OUT_OUT0_OFF)

/** \brief PORT OUT.OUT1 bit offset */
#define PORT_OUT_OUT1_OFF 1u
/** \brief PORT OUT.OUT1 bit mask */
#define PORT_OUT_OUT1_MSK (0x1u << PORT_OUT_OUT1_OFF)

/** \brief PORT OUT.OUT2 bit offset */
#define PORT_OUT_OUT2_OFF 2u
/** \brief PORT OUT.OUT2 bit mask */
#define PORT_OUT_OUT2_MSK (0x1u << PORT_OUT_OUT2_OFF)

/** \brief PORT OUT.OUT3 bit offset */
#define PORT_OUT_OUT3_OFF 3u
/** \brief PORT OUT.OUT3 bit mask */
#define PORT_OUT_OUT3_MSK (0x1u << PORT_OUT_OUT3_OFF)

/** \brief PORT OUT.OUT4 bit offset */
#define PORT_OUT_OUT4_OFF 4u
/** \brief PORT OUT.OUT4 bit mask */
#define PORT_OUT_OUT4_MSK (0x1u << PORT_OUT_OUT4_OFF)

/** \brief PORT OUT.OUT5 bit offset */
#define PORT_OUT_OUT5_OFF 5u
/** \brief PORT OUT.OUT5 bit mask */
#define PORT_OUT_OUT5_MSK (0x1u << PORT_OUT_OUT5_OFF)

/** \brief PORT OUT.OUT6 bit offset */
#define PORT_OUT_OUT6_OFF 6u
/** \brief PORT OUT.OUT6 bit mask */
#define PORT_OUT_OUT6_MSK (0x1u << PORT_OUT_OUT6_OFF)

/** \brief PORT OUT.OUT7 bit offset */
#define PORT_OUT_OUT7_OFF 7u
/** \brief PORT OUT.OUT7 bit mask */
#define PORT_OUT_OUT7_MSK (0x1u << PORT_OUT_OUT7_OFF)

/** \brief PORT OUT.OUT8 bit offset */
#define PORT_OUT_OUT8_OFF 8u
/** \brief PORT OUT.OUT8 bit mask */
#define PORT_OUT_OUT8_MSK (0x1u << PORT_OUT_OUT8_OFF)

/** \brief PORT OUT.OUT9 bit offset */
#define PORT_OUT_OUT9_OFF 9u
/** \brief PORT OUT.OUT9 bit mask */
#define PORT_OUT_OUT9_MSK (0x1u << PORT_OUT_OUT9_OFF)

/** \brief PORT OUT.OUT10 bit offset */
#define PORT_OUT_OUT10_OFF 10u
/** \brief PORT OUT.OUT10 bit mask */
#define PORT_OUT_OUT10_MSK (0x1u << PORT_OUT_OUT10_OFF)

/** \brief PORT OUT.OUT11 bit offset */
#define PORT_OUT_OUT11_OFF 11u
/** \brief PORT OUT.OUT11 bit mask */
#define PORT_OUT_OUT11_MSK (0x1u << PORT_OUT_OUT11_OFF)

/** \brief PORT OUT.OUT12 bit offset */
#define PORT_OUT_OUT12_OFF 12u
/** \brief PORT OUT.OUT12 bit mask */
#define PORT_OUT_OUT12_MSK (0x1u << PORT_OUT_OUT12_OFF)

/** \brief PORT OUT.OUT13 bit offset */
#define PORT_OUT_OUT13_OFF 13u
/** \brief PORT OUT.OUT13 bit mask */
#define PORT_OUT_OUT13_MSK (0x1u << PORT_OUT_OUT13_OFF)

/** \brief PORT OUT.OUT14 bit offset */
#define PORT_OUT_OUT14_OFF 14u
/** \brief PORT OUT.OUT14 bit mask */
#define PORT_OUT_OUT14_MSK (0x1u << PORT_OUT_OUT14_OFF)

/** \brief PORT OUT.OUT15 bit offset */
#define PORT_OUT_OUT15_OFF 15u
/** \brief PORT OUT.OUT15 bit mask */
#define PORT_OUT_OUT15_MSK (0x1u << PORT_OUT_OUT15_OFF)

/** \brief PORT OUT.OUT16 bit offset */
#define PORT_OUT_OUT16_OFF 16u
/** \brief PORT OUT.OUT16 bit mask */
#define PORT_OUT_OUT16_MSK (0x1u << PORT_OUT_OUT16_OFF)

/** \brief PORT OUT.OUT17 bit offset */
#define PORT_OUT_OUT17_OFF 17u
/** \brief PORT OUT.OUT17 bit mask */
#define PORT_OUT_OUT17_MSK (0x1u << PORT_OUT_OUT17_OFF)

/** \brief PORT OUT.OUT18 bit offset */
#define PORT_OUT_OUT18_OFF 18u
/** \brief PORT OUT.OUT18 bit mask */
#define PORT_OUT_OUT18_MSK (0x1u << PORT_OUT_OUT18_OFF)

/** \brief PORT OUT.OUT19 bit offset */
#define PORT_OUT_OUT19_OFF 19u
/** \brief PORT OUT.OUT19 bit mask */
#define PORT_OUT_OUT19_MSK (0x1u << PORT_OUT_OUT19_OFF)

/** \brief PORT OUT.OUT20 bit offset */
#define PORT_OUT_OUT20_OFF 20u
/** \brief PORT OUT.OUT20 bit mask */
#define PORT_OUT_OUT20_MSK (0x1u << PORT_OUT_OUT20_OFF)

/** \brief PORT OUT.OUT21 bit offset */
#define PORT_OUT_OUT21_OFF 21u
/** \brief PORT OUT.OUT21 bit mask */
#define PORT_OUT_OUT21_MSK (0x1u << PORT_OUT_OUT21_OFF)

/** \brief PORT OUT.OUT22 bit offset */
#define PORT_OUT_OUT22_OFF 22u
/** \brief PORT OUT.OUT22 bit mask */
#define PORT_OUT_OUT22_MSK (0x1u << PORT_OUT_OUT22_OFF)

/** \brief PORT OUT.OUT23 bit offset */
#define PORT_OUT_OUT23_OFF 23u
/** \brief PORT OUT.OUT23 bit mask */
#define PORT_OUT_OUT23_MSK (0x1u << PORT_OUT_OUT23_OFF)

/** \brief PORT OUT.OUT24 bit offset */
#define PORT_OUT_OUT24_OFF 24u
/** \brief PORT OUT.OUT24 bit mask */
#define PORT_OUT_OUT24_MSK (0x1u << PORT_OUT_OUT24_OFF)

/** \brief PORT OUT.OUT25 bit offset */
#define PORT_OUT_OUT25_OFF 25u
/** \brief PORT OUT.OUT25 bit mask */
#define PORT_OUT_OUT25_MSK (0x1u << PORT_OUT_OUT25_OFF)

/** \brief PORT OUT.OUT26 bit offset */
#define PORT_OUT_OUT26_OFF 26u
/** \brief PORT OUT.OUT26 bit mask */
#define PORT_OUT_OUT26_MSK (0x1u << PORT_OUT_OUT26_OFF)

/** \brief PORT OUT.OUT27 bit offset */
#define PORT_OUT_OUT27_OFF 27u
/** \brief PORT OUT.OUT27 bit mask */
#define PORT_OUT_OUT27_MSK (0x1u << PORT_OUT_OUT27_OFF)

/** \brief PORT OUT.OUT28 bit offset */
#define PORT_OUT_OUT28_OFF 28u
/** \brief PORT OUT.OUT28 bit mask */
#define PORT_OUT_OUT28_MSK (0x1u << PORT_OUT_OUT28_OFF)

/** \brief PORT OUT.OUT29 bit offset */
#define PORT_OUT_OUT29_OFF 29u
/** \brief PORT OUT.OUT29 bit mask */
#define PORT_OUT_OUT29_MSK (0x1u << PORT_OUT_OUT29_OFF)

/** \brief PORT OUT.OUT30 bit offset */
#define PORT_OUT_OUT30_OFF 30u
/** \brief PORT OUT.OUT30 bit mask */
#define PORT_OUT_OUT30_MSK (0x1u << PORT_OUT_OUT30_OFF)

/** \brief PORT OUT.OUT31 bit offset */
#define PORT_OUT_OUT31_OFF 31u
/** \brief PORT OUT.OUT31 bit mask */
#define PORT_OUT_OUT31_MSK (0x1u << PORT_OUT_OUT31_OFF)

/**@}*/

/** \name PORT PINCFG register */
/**@{*/

/** \brief PORT PINCFG register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Peripheral multiplexer enable */
		uint8_t PMUXEN:1;
		/** \brief Input buffer enable */
		uint8_t INEN:1;
		/** \brief Pull enable */
		uint8_t PULLEN:1;
		/** \brief Reserved */
		uint8_t :3;
		/** \brief Output driver strength selection */
		uint8_t DRVSTR:1;
		/** \brief Reserved */
		uint8_t :1;
	} B;
} port_pincfg_t;

/** \brief PORT PINCFG0 register address offset */
#define PORT_PINCFG0_OFF 0x40u
/** \brief PORT PINCFG1 register address offset */
#define PORT_PINCFG1_OFF 0x41u
/** \brief PORT PINCFG2 register address offset */
#define PORT_PINCFG2_OFF 0x42u
/** \brief PORT PINCFG3 register address offset */
#define PORT_PINCFG3_OFF 0x43u
/** \brief PORT PINCFG4 register address offset */
#define PORT_PINCFG4_OFF 0x44u
/** \brief PORT PINCFG5 register address offset */
#define PORT_PINCFG5_OFF 0x45u
/** \brief PORT PINCFG6 register address offset */
#define PORT_PINCFG6_OFF 0x46u
/** \brief PORT PINCFG7 register address offset */
#define PORT_PINCFG7_OFF 0x47u
/** \brief PORT PINCFG8 register address offset */
#define PORT_PINCFG8_OFF 0x48u
/** \brief PORT PINCFG9 register address offset */
#define PORT_PINCFG9_OFF 0x49u
/** \brief PORT PINCFG10 register address offset */
#define PORT_PINCFG10_OFF 0x4Au
/** \brief PORT PINCFG11 register address offset */
#define PORT_PINCFG11_OFF 0x4Bu
/** \brief PORT PINCFG12 register address offset */
#define PORT_PINCFG12_OFF 0x4Cu
/** \brief PORT PINCFG13 register address offset */
#define PORT_PINCFG13_OFF 0x4Du
/** \brief PORT PINCFG14 register address offset */
#define PORT_PINCFG14_OFF 0x4Eu
/** \brief PORT PINCFG15 register address offset */
#define PORT_PINCFG15_OFF 0x4Fu
/** \brief PORT PINCFG16 register address offset */
#define PORT_PINCFG16_OFF 0x50u
/** \brief PORT PINCFG17 register address offset */
#define PORT_PINCFG17_OFF 0x51u
/** \brief PORT PINCFG18 register address offset */
#define PORT_PINCFG18_OFF 0x52u
/** \brief PORT PINCFG19 register address offset */
#define PORT_PINCFG19_OFF 0x53u
/** \brief PORT PINCFG20 register address offset */
#define PORT_PINCFG20_OFF 0x54u
/** \brief PORT PINCFG21 register address offset */
#define PORT_PINCFG21_OFF 0x55u
/** \brief PORT PINCFG22 register address offset */
#define PORT_PINCFG22_OFF 0x56u
/** \brief PORT PINCFG23 register address offset */
#define PORT_PINCFG23_OFF 0x57u
/** \brief PORT PINCFG24 register address offset */
#define PORT_PINCFG24_OFF 0x58u
/** \brief PORT PINCFG25 register address offset */
#define PORT_PINCFG25_OFF 0x59u
/** \brief PORT PINCFG26 register address offset */
#define PORT_PINCFG26_OFF 0x5Au
/** \brief PORT PINCFG27 register address offset */
#define PORT_PINCFG27_OFF 0x5Bu
/** \brief PORT PINCFG28 register address offset */
#define PORT_PINCFG28_OFF 0x5Cu
/** \brief PORT PINCFG29 register address offset */
#define PORT_PINCFG29_OFF 0x5Du
/** \brief PORT PINCFG30 register address offset */
#define PORT_PINCFG30_OFF 0x5Eu
/** \brief PORT PINCFG31 register address offset */
#define PORT_PINCFG31_OFF 0x5Fu

/** \brief PORT PINCFG0 register address */
#define PORT_PINCFG0_ADDR (PORT_ADDR + PORT_PINCFG0_OFF)
/** \brief PORT PINCFG1 register address */
#define PORT_PINCFG1_ADDR (PORT_ADDR + PORT_PINCFG1_OFF)
/** \brief PORT PINCFG2 register address */
#define PORT_PINCFG2_ADDR (PORT_ADDR + PORT_PINCFG2_OFF)
/** \brief PORT PINCFG3 register address */
#define PORT_PINCFG3_ADDR (PORT_ADDR + PORT_PINCFG3_OFF)
/** \brief PORT PINCFG4 register address */
#define PORT_PINCFG4_ADDR (PORT_ADDR + PORT_PINCFG4_OFF)
/** \brief PORT PINCFG5 register address */
#define PORT_PINCFG5_ADDR (PORT_ADDR + PORT_PINCFG5_OFF)
/** \brief PORT PINCFG6 register address */
#define PORT_PINCFG6_ADDR (PORT_ADDR + PORT_PINCFG6_OFF)
/** \brief PORT PINCFG7 register address */
#define PORT_PINCFG7_ADDR (PORT_ADDR + PORT_PINCFG7_OFF)
/** \brief PORT PINCFG8 register address */
#define PORT_PINCFG8_ADDR (PORT_ADDR + PORT_PINCFG8_OFF)
/** \brief PORT PINCFG9 register address */
#define PORT_PINCFG9_ADDR (PORT_ADDR + PORT_PINCFG9_OFF)
/** \brief PORT PINCFG10 register address */
#define PORT_PINCFG10_ADDR (PORT_ADDR + PORT_PINCFG10_OFF)
/** \brief PORT PINCFG11 register address */
#define PORT_PINCFG11_ADDR (PORT_ADDR + PORT_PINCFG11_OFF)
/** \brief PORT PINCFG12 register address */
#define PORT_PINCFG12_ADDR (PORT_ADDR + PORT_PINCFG12_OFF)
/** \brief PORT PINCFG13 register address */
#define PORT_PINCFG13_ADDR (PORT_ADDR + PORT_PINCFG13_OFF)
/** \brief PORT PINCFG14 register address */
#define PORT_PINCFG14_ADDR (PORT_ADDR + PORT_PINCFG14_OFF)
/** \brief PORT PINCFG15 register address */
#define PORT_PINCFG15_ADDR (PORT_ADDR + PORT_PINCFG15_OFF)
/** \brief PORT PINCFG16 register address */
#define PORT_PINCFG16_ADDR (PORT_ADDR + PORT_PINCFG16_OFF)
/** \brief PORT PINCFG17 register address */
#define PORT_PINCFG17_ADDR (PORT_ADDR + PORT_PINCFG17_OFF)
/** \brief PORT PINCFG18 register address */
#define PORT_PINCFG18_ADDR (PORT_ADDR + PORT_PINCFG18_OFF)
/** \brief PORT PINCFG19 register address */
#define PORT_PINCFG19_ADDR (PORT_ADDR + PORT_PINCFG19_OFF)
/** \brief PORT PINCFG20 register address */
#define PORT_PINCFG20_ADDR (PORT_ADDR + PORT_PINCFG20_OFF)
/** \brief PORT PINCFG21 register address */
#define PORT_PINCFG21_ADDR (PORT_ADDR + PORT_PINCFG21_OFF)
/** \brief PORT PINCFG22 register address */
#define PORT_PINCFG22_ADDR (PORT_ADDR + PORT_PINCFG22_OFF)
/** \brief PORT PINCFG23 register address */
#define PORT_PINCFG23_ADDR (PORT_ADDR + PORT_PINCFG23_OFF)
/** \brief PORT PINCFG24 register address */
#define PORT_PINCFG24_ADDR (PORT_ADDR + PORT_PINCFG24_OFF)
/** \brief PORT PINCFG25 register address */
#define PORT_PINCFG25_ADDR (PORT_ADDR + PORT_PINCFG25_OFF)
/** \brief PORT PINCFG26 register address */
#define PORT_PINCFG26_ADDR (PORT_ADDR + PORT_PINCFG26_OFF)
/** \brief PORT PINCFG27 register address */
#define PORT_PINCFG27_ADDR (PORT_ADDR + PORT_PINCFG27_OFF)
/** \brief PORT PINCFG28 register address */
#define PORT_PINCFG28_ADDR (PORT_ADDR + PORT_PINCFG28_OFF)
/** \brief PORT PINCFG29 register address */
#define PORT_PINCFG29_ADDR (PORT_ADDR + PORT_PINCFG29_OFF)
/** \brief PORT PINCFG30 register address */
#define PORT_PINCFG30_ADDR (PORT_ADDR + PORT_PINCFG30_OFF)
/** \brief PORT PINCFG31 register address */
#define PORT_PINCFG31_ADDR (PORT_ADDR + PORT_PINCFG31_OFF)

/** \brief PORT PINCFG0 register */
#define PORT_PINCFG0 (*((volatile port_pincfg_t*) PORT_PINCFG0_ADDR))
/** \brief PORT PINCFG1 register */
#define PORT_PINCFG1 (*((volatile port_pincfg_t*) PORT_PINCFG1_ADDR))
/** \brief PORT PINCFG2 register */
#define PORT_PINCFG2 (*((volatile port_pincfg_t*) PORT_PINCFG2_ADDR))
/** \brief PORT PINCFG3 register */
#define PORT_PINCFG3 (*((volatile port_pincfg_t*) PORT_PINCFG3_ADDR))
/** \brief PORT PINCFG4 register */
#define PORT_PINCFG4 (*((volatile port_pincfg_t*) PORT_PINCFG4_ADDR))
/** \brief PORT PINCFG5 register */
#define PORT_PINCFG5 (*((volatile port_pincfg_t*) PORT_PINCFG5_ADDR))
/** \brief PORT PINCFG6 register */
#define PORT_PINCFG6 (*((volatile port_pincfg_t*) PORT_PINCFG6_ADDR))
/** \brief PORT PINCFG7 register */
#define PORT_PINCFG7 (*((volatile port_pincfg_t*) PORT_PINCFG7_ADDR))
/** \brief PORT PINCFG8 register */
#define PORT_PINCFG8 (*((volatile port_pincfg_t*) PORT_PINCFG8_ADDR))
/** \brief PORT PINCFG9 register */
#define PORT_PINCFG9 (*((volatile port_pincfg_t*) PORT_PINCFG9_ADDR))
/** \brief PORT PINCFG10 register */
#define PORT_PINCFG10 (*((volatile port_pincfg_t*) PORT_PINCFG10_ADDR))
/** \brief PORT PINCFG11 register */
#define PORT_PINCFG11 (*((volatile port_pincfg_t*) PORT_PINCFG11_ADDR))
/** \brief PORT PINCFG12 register */
#define PORT_PINCFG12 (*((volatile port_pincfg_t*) PORT_PINCFG12_ADDR))
/** \brief PORT PINCFG13 register */
#define PORT_PINCFG13 (*((volatile port_pincfg_t*) PORT_PINCFG13_ADDR))
/** \brief PORT PINCFG14 register */
#define PORT_PINCFG14 (*((volatile port_pincfg_t*) PORT_PINCFG14_ADDR))
/** \brief PORT PINCFG15 register */
#define PORT_PINCFG15 (*((volatile port_pincfg_t*) PORT_PINCFG15_ADDR))
/** \brief PORT PINCFG16 register */
#define PORT_PINCFG16 (*((volatile port_pincfg_t*) PORT_PINCFG16_ADDR))
/** \brief PORT PINCFG17 register */
#define PORT_PINCFG17 (*((volatile port_pincfg_t*) PORT_PINCFG17_ADDR))
/** \brief PORT PINCFG18 register */
#define PORT_PINCFG18 (*((volatile port_pincfg_t*) PORT_PINCFG18_ADDR))
/** \brief PORT PINCFG19 register */
#define PORT_PINCFG19 (*((volatile port_pincfg_t*) PORT_PINCFG19_ADDR))
/** \brief PORT PINCFG20 register */
#define PORT_PINCFG20 (*((volatile port_pincfg_t*) PORT_PINCFG20_ADDR))
/** \brief PORT PINCFG21 register */
#define PORT_PINCFG21 (*((volatile port_pincfg_t*) PORT_PINCFG21_ADDR))
/** \brief PORT PINCFG22 register */
#define PORT_PINCFG22 (*((volatile port_pincfg_t*) PORT_PINCFG22_ADDR))
/** \brief PORT PINCFG23 register */
#define PORT_PINCFG23 (*((volatile port_pincfg_t*) PORT_PINCFG23_ADDR))
/** \brief PORT PINCFG24 register */
#define PORT_PINCFG24 (*((volatile port_pincfg_t*) PORT_PINCFG24_ADDR))
/** \brief PORT PINCFG25 register */
#define PORT_PINCFG25 (*((volatile port_pincfg_t*) PORT_PINCFG25_ADDR))
/** \brief PORT PINCFG26 register */
#define PORT_PINCFG26 (*((volatile port_pincfg_t*) PORT_PINCFG26_ADDR))
/** \brief PORT PINCFG27 register */
#define PORT_PINCFG27 (*((volatile port_pincfg_t*) PORT_PINCFG27_ADDR))
/** \brief PORT PINCFG28 register */
#define PORT_PINCFG28 (*((volatile port_pincfg_t*) PORT_PINCFG28_ADDR))
/** \brief PORT PINCFG29 register */
#define PORT_PINCFG29 (*((volatile port_pincfg_t*) PORT_PINCFG29_ADDR))
/** \brief PORT PINCFG30 register */
#define PORT_PINCFG30 (*((volatile port_pincfg_t*) PORT_PINCFG30_ADDR))
/** \brief PORT PINCFG31 register */
#define PORT_PINCFG31 (*((volatile port_pincfg_t*) PORT_PINCFG31_ADDR))

/** \brief PORT PINCFG.PMUXEN bit offset */
#define PORT_PINCFG_PMUXEN_OFF 0u
/** \brief PORT PINCFG.PMUXEN bit mask */
#define PORT_PINCFG_PMUXEN_MSK (0x1u << PORT_PINCFG_PMUXEN_OFF)

/** \brief PORT PINCFG.INEN bit offset */
#define PORT_PINCFG_INEN_OFF 1u
/** \brief PORT PINCFG.INEN bit mask */
#define PORT_PINCFG_INEN_MSK (0x1u << PORT_PINCFG_INEN_OFF)

/** \brief PORT PINCFG.PULLEN bit offset */
#define PORT_PINCFG_PULLEN_OFF 2u
/** \brief PORT PINCFG.PULLEN bit mask */
#define PORT_PINCFG_PULLEN_MSK (0x1u << PORT_PINCFG_PULLEN_OFF)

/** \brief PORT PINCFG.DRVSTR bit offset */
#define PORT_PINCFG_DRVSTR_OFF 6u
/** \brief PORT PINCFG.DRVSTR bit mask */
#define PORT_PINCFG_DRVSTR_MSK (0x1u << PORT_PINCFG_DRVSTR_OFF)

/**@}*/

/** \name PORT PMUX register */
/**@{*/

/** \brief PORT PMUX register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Peripheral multiplexing for even-numbered pin */
		uint8_t PMUXE:4;
		/** \brief Peripheral multiplexing for odd-numbered pin */
		uint8_t PMUXO:4;
	} B;
} port_pmux_t;

/** \brief PORT PMUX0 register address offset */
#define PORT_PMUX0_OFF 0x30u
/** \brief PORT PMUX1 register address offset */
#define PORT_PMUX1_OFF 0x31u
/** \brief PORT PMUX2 register address offset */
#define PORT_PMUX2_OFF 0x32u
/** \brief PORT PMUX3 register address offset */
#define PORT_PMUX3_OFF 0x33u
/** \brief PORT PMUX4 register address offset */
#define PORT_PMUX4_OFF 0x34u
/** \brief PORT PMUX5 register address offset */
#define PORT_PMUX5_OFF 0x35u
/** \brief PORT PMUX6 register address offset */
#define PORT_PMUX6_OFF 0x36u
/** \brief PORT PMUX7 register address offset */
#define PORT_PMUX7_OFF 0x37u
/** \brief PORT PMUX8 register address offset */
#define PORT_PMUX8_OFF 0x38u
/** \brief PORT PMUX9 register address offset */
#define PORT_PMUX9_OFF 0x39u
/** \brief PORT PMUX10 register address offset */
#define PORT_PMUX10_OFF 0x3Au
/** \brief PORT PMUX11 register address offset */
#define PORT_PMUX11_OFF 0x3Bu
/** \brief PORT PMUX12 register address offset */
#define PORT_PMUX12_OFF 0x3Cu
/** \brief PORT PMUX13 register address offset */
#define PORT_PMUX13_OFF 0x3Du
/** \brief PORT PMUX14 register address offset */
#define PORT_PMUX14_OFF 0x3Eu
/** \brief PORT PMUX15 register address offset */
#define PORT_PMUX15_OFF 0x3Fu

/** \brief PORT PMUX0 register address */
#define PORT_PMUX0_ADDR (PORT_ADDR + PORT_PMUX0_OFF)
/** \brief PORT PMUX1 register address */
#define PORT_PMUX1_ADDR (PORT_ADDR + PORT_PMUX1_OFF)
/** \brief PORT PMUX2 register address */
#define PORT_PMUX2_ADDR (PORT_ADDR + PORT_PMUX2_OFF)
/** \brief PORT PMUX3 register address */
#define PORT_PMUX3_ADDR (PORT_ADDR + PORT_PMUX3_OFF)
/** \brief PORT PMUX4 register address */
#define PORT_PMUX4_ADDR (PORT_ADDR + PORT_PMUX4_OFF)
/** \brief PORT PMUX5 register address */
#define PORT_PMUX5_ADDR (PORT_ADDR + PORT_PMUX5_OFF)
/** \brief PORT PMUX6 register address */
#define PORT_PMUX6_ADDR (PORT_ADDR + PORT_PMUX6_OFF)
/** \brief PORT PMUX7 register address */
#define PORT_PMUX7_ADDR (PORT_ADDR + PORT_PMUX7_OFF)
/** \brief PORT PMUX8 register address */
#define PORT_PMUX8_ADDR (PORT_ADDR + PORT_PMUX8_OFF)
/** \brief PORT PMUX9 register address */
#define PORT_PMUX9_ADDR (PORT_ADDR + PORT_PMUX9_OFF)
/** \brief PORT PMUX10 register address */
#define PORT_PMUX10_ADDR (PORT_ADDR + PORT_PMUX10_OFF)
/** \brief PORT PMUX11 register address */
#define PORT_PMUX11_ADDR (PORT_ADDR + PORT_PMUX11_OFF)
/** \brief PORT PMUX12 register address */
#define PORT_PMUX12_ADDR (PORT_ADDR + PORT_PMUX12_OFF)
/** \brief PORT PMUX13 register address */
#define PORT_PMUX13_ADDR (PORT_ADDR + PORT_PMUX13_OFF)
/** \brief PORT PMUX14 register address */
#define PORT_PMUX14_ADDR (PORT_ADDR + PORT_PMUX14_OFF)
/** \brief PORT PMUX15 register address */
#define PORT_PMUX15_ADDR (PORT_ADDR + PORT_PMUX15_OFF)

/** \brief PORT PMUX0 register */
#define PORT_PMUX0 (*((volatile port_pmux_t*) PORT_PMUX0_ADDR))
/** \brief PORT PMUX1 register */
#define PORT_PMUX1 (*((volatile port_pmux_t*) PORT_PMUX1_ADDR))
/** \brief PORT PMUX2 register */
#define PORT_PMUX2 (*((volatile port_pmux_t*) PORT_PMUX2_ADDR))
/** \brief PORT PMUX3 register */
#define PORT_PMUX3 (*((volatile port_pmux_t*) PORT_PMUX3_ADDR))
/** \brief PORT PMUX4 register */
#define PORT_PMUX4 (*((volatile port_pmux_t*) PORT_PMUX4_ADDR))
/** \brief PORT PMUX5 register */
#define PORT_PMUX5 (*((volatile port_pmux_t*) PORT_PMUX5_ADDR))
/** \brief PORT PMUX6 register */
#define PORT_PMUX6 (*((volatile port_pmux_t*) PORT_PMUX6_ADDR))
/** \brief PORT PMUX7 register */
#define PORT_PMUX7 (*((volatile port_pmux_t*) PORT_PMUX7_ADDR))
/** \brief PORT PMUX8 register */
#define PORT_PMUX8 (*((volatile port_pmux_t*) PORT_PMUX8_ADDR))
/** \brief PORT PMUX9 register */
#define PORT_PMUX9 (*((volatile port_pmux_t*) PORT_PMUX9_ADDR))
/** \brief PORT PMUX10 register */
#define PORT_PMUX10 (*((volatile port_pmux_t*) PORT_PMUX10_ADDR))
/** \brief PORT PMUX11 register */
#define PORT_PMUX11 (*((volatile port_pmux_t*) PORT_PMUX11_ADDR))
/** \brief PORT PMUX12 register */
#define PORT_PMUX12 (*((volatile port_pmux_t*) PORT_PMUX12_ADDR))
/** \brief PORT PMUX13 register */
#define PORT_PMUX13 (*((volatile port_pmux_t*) PORT_PMUX13_ADDR))
/** \brief PORT PMUX14 register */
#define PORT_PMUX14 (*((volatile port_pmux_t*) PORT_PMUX14_ADDR))
/** \brief PORT PMUX15 register */
#define PORT_PMUX15 (*((volatile port_pmux_t*) PORT_PMUX15_ADDR))

/** \brief PORT PMUX.PMUXE bit offset */
#define PORT_PMUX_PMUXE_OFF 0u
/** \brief PORT PMUX.PMUXE bit mask */
#define PORT_PMUX_PMUXE_MSK (0xFu << PORT_PMUX_PMUXE)

/** \brief PORT PMUX.PMUXO bit offset */
#define PORT_PMUX_PMUXO_OFF 4u
/** \brief PORT PMUX.PMUXO bit mask */
#define PORT_PMUX_PMUXO_MSK (0xFu << PORT_PMUX_PMUXO)

/**@}*/

#endif /* SAMFD_PORT_H */
