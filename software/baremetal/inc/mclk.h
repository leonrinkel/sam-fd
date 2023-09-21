#ifndef SAMFD_MCLK_H
#define SAMFD_MCLK_H

#include <stdint.h>

/** \brief MCLK registers base address */
#define MCLK_ADDR 0x40000800u

/** \name MCLK AHBMASK register */
/**@{*/

/** \brief MCLK AHBMASK register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief APBA AHB clock enable */
		uint32_t APBA:1;
		/** \brief APBB AHB clock enable */
		uint32_t APBB:1;
		/** \brief APBC AHB clock enable */
		uint32_t APBC:1;
		/** \brief DSU AHB clock enable */
		uint32_t DSU:1;
		/** \brief HMATRIXHS AHB clock enable */
		uint32_t HMATRIXHS:1;
		/** \brief NVMCTRL AHB clock enable */
		uint32_t NVMCTRL:1;
		/** \brief HSRAM AHB clock enable */
		uint32_t HSRAM:1;
		/** \brief DMAC AHB clock enable */
		uint32_t DMAC:1;
		/** \brief CAN0 AHB clock enable */
		uint32_t CAN0:1;
		/** \brief CAN1 AHB clock enable */
		uint32_t CAN1:1;
		/** \brief PAC AHB clock enable */
		uint32_t PAC:1;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief DIVAS AHB clock enable */
		uint32_t DIVAS:1;
		/** \brief APBD AHB clock enable */
		uint32_t APBD:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} mclk_ahbmask_t;

/** \brief MCLK AHBMASK register address offset */
#define MCLK_AHBMASK_OFF 0x10u

/** \brief MCLK AHBMASK register address */
#define MCLK_AHBMASK_ADDR (MCLK_ADDR + MCLK_AHBMASK_OFF)

/** \brief MCLK AHBMASK register */
#define MCLK_AHBMASK (*((volatile mclk_ahbmask_t*) MCLK_AHBMASK_ADDR))

/** \brief MCLK AHBMASK.APBA bit offset */
#define MCLK_AHBMASK_APBA_OFF 0u
/** \brief MCLK AHBMASK.APBA bit mask*/
#define MCLK_AHBMASK_APBA_MSK (0x1u << MCLK_AHBMASK_APBA_OFF)

/** \brief MCLK AHBMASK.APBB bit offset */
#define MCLK_AHBMASK_APBB_OFF 1u
/** \brief MCLK AHBMASK.APBB bit mask*/
#define MCLK_AHBMASK_APBB_MSK (0x1u << MCLK_AHBMASK_APBB_OFF)

/** \brief MCLK AHBMASK.APBC bit offset */
#define MCLK_AHBMASK_APBC_OFF 2u
/** \brief MCLK AHBMASK.APBC bit mask*/
#define MCLK_AHBMASK_APBC_MSK (0x1u << MCLK_AHBMASK_APBC_OFF)

/** \brief MCLK AHBMASK.DSU bit offset */
#define MCLK_AHBMASK_DSU_OFF 3u
/** \brief MCLK AHBMASK.DSU bit mask*/
#define MCLK_AHBMASK_DSU_MSK (0x1u << MCLK_AHBMASK_DSU_OFF)

/** \brief MCLK AHBMASK.HMATRIXHS bit offset */
#define MCLK_AHBMASK_HMATRIXHS_OFF 4u
/** \brief MCLK AHBMASK.HMATRIXHS bit mask*/
#define MCLK_AHBMASK_HMATRIXHS_MSK (0x1u << MCLK_AHBMASK_HMATRIXHS_OFF)

/** \brief MCLK AHBMASK.NVMCTRL bit offset */
#define MCLK_AHBMASK_NVMCTRL_OFF 5u
/** \brief MCLK AHBMASK.NVMCTRL bit mask*/
#define MCLK_AHBMASK_NVMCTRL_MSK (0x1u << MCLK_AHBMASK_NVMCTRL_OFF)

/** \brief MCLK AHBMASK.HSRAM bit offset */
#define MCLK_AHBMASK_HSRAM_OFF 6u
/** \brief MCLK AHBMASK.HSRAM bit mask*/
#define MCLK_AHBMASK_HSRAM_MSK (0x1u << MCLK_AHBMASK_HSRAM_OFF)

/** \brief MCLK AHBMASK.DMAC bit offset */
#define MCLK_AHBMASK_DMAC_OFF 7u
/** \brief MCLK AHBMASK.DMAC bit mask*/
#define MCLK_AHBMASK_DMAC_MSK (0x1u << MCLK_AHBMASK_DMAC_OFF)

/** \brief MCLK AHBMASK.CAN0 bit offset */
#define MCLK_AHBMASK_CAN0_OFF 8u
/** \brief MCLK AHBMASK.CAN0 bit mask*/
#define MCLK_AHBMASK_CAN0_MSK (0x1u << MCLK_AHBMASK_CAN0_OFF)

/** \brief MCLK AHBMASK.CAN1 bit offset */
#define MCLK_AHBMASK_CAN1_OFF 9u
/** \brief MCLK AHBMASK.CAN1 bit mask*/
#define MCLK_AHBMASK_CAN1_MSK (0x1u << MCLK_AHBMASK_CAN1_OFF)

/** \brief MCLK AHBMASK.PAC bit offset */
#define MCLK_AHBMASK_PAC_OFF 10u
/** \brief MCLK AHBMASK.PAC bit mask*/
#define MCLK_AHBMASK_PAC_MSK (0x1u << MCLK_AHBMASK_PAC_OFF)

/** \brief MCLK AHBMASK.DIVAS bit offset */
#define MCLK_AHBMASK_DIVAS_OFF 12u
/** \brief MCLK AHBMASK.DIVAS bit mask*/
#define MCLK_AHBMASK_DIVAS_MSK (0x1u << MCLK_AHBMASK_DIVAS_OFF)

/** \brief MCLK AHBMASK.APBD bit offset */
#define MCLK_AHBMASK_APBD_OFF 13u
/** \brief MCLK AHBMASK.APBD bit mask*/
#define MCLK_AHBMASK_APBD_MSK (0x1u << MCLK_AHBMASK_APBD_OFF)

/**@}*/

/** \name MCLK APBAMASK register */
/**@{*/

/** \brief MCLK APBAMASK register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief PAC APBA clock enable */
		uint32_t PAC:1;
		/** \brief PM APBA clock enable */
		uint32_t PM:1;
		/** \brief MCLK APBA clock enable */
		uint32_t MCLK:1;
		/** \brief RSTC APBA clock enable */
		uint32_t RSTC:1;
		/** \brief OSCCTRL APBA clock enable */
		uint32_t OSCCTRL:1;
		/** \brief OSC32KCTRL APBA clock enable */
		uint32_t OSC32KCTRL:1;
		/** \brief SUPC APBA clock enable */
		uint32_t SUPC:1;
		/** \brief GCLK APBA clock enable */
		uint32_t GCLK:1;
		/** \brief WDT APBA clock enable */
		uint32_t WDT:1;
		/** \brief RTC APBA clock enable */
		uint32_t RTC:1;
		/** \brief EIC APBA clock enable */
		uint32_t EIC:1;
		/** \brief FREQM APBA clock enable */
		uint32_t FREQM:1;
		/** \brief TSENS APBA clock enable */
		uint32_t TSENS:1;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} mclk_apbamask_t;

/** \brief MCLK APBAMASK register address offset */
#define MCLK_APBAMASK_OFF 0x14u

/** \brief MCLK APBAMASK register address */
#define MCLK_APBAMASK_ADDR (MCLK_ADDR + MCLK_APBAMASK_OFF)

/** \brief MCLK APBAMASK register */
#define MCLK_APBAMASK (*((volatile mclk_apbamask_t*) MCLK_APBAMASK_ADDR))

/** \brief MCLK APBAMASK.PAC bit offset */
#define MCLK_APBAMASK_PAC_OFF 0u
/** \brief MCLK APBAMASK.PAC bit mask */
#define MCLK_APBAMASK_PAC_MSK (0x1u << MCLK_APBAMASK_PAC_OFF)

/** \brief MCLK APBAMASK.PM bit offset */
#define MCLK_APBAMASK_PM_OFF 1u
/** \brief MCLK APBAMASK.PM bit mask */
#define MCLK_APBAMASK_PM_MSK (0x1u << MCLK_APBAMASK_PM_OFF)

/** \brief MCLK APBAMASK.MCLK bit offset */
#define MCLK_APBAMASK_MCLK_OFF 2u
/** \brief MCLK APBAMASK.MCLK bit mask */
#define MCLK_APBAMASK_MCLK_MSK (0x1u << MCLK_APBAMASK_MCLK_OFF)

/** \brief MCLK APBAMASK.RSTC bit offset */
#define MCLK_APBAMASK_RSTC_OFF 3u
/** \brief MCLK APBAMASK.RSTC bit mask */
#define MCLK_APBAMASK_RSTC_MSK (0x1u << MCLK_APBAMASK_RSTC_OFF)

/** \brief MCLK APBAMASK.OSCCTRL bit offset */
#define MCLK_APBAMASK_OSCCTRL_OFF 4u
/** \brief MCLK APBAMASK.OSCCTRL bit mask */
#define MCLK_APBAMASK_OSCCTRL_MSK (0x1u << MCLK_APBAMASK_OSCCTRL_OFF)

/** \brief MCLK APBAMASK.OSC32KCTRL bit offset */
#define MCLK_APBAMASK_OSC32KCTRL_OFF 5u
/** \brief MCLK APBAMASK.OSC32KCTRL bit mask */
#define MCLK_APBAMASK_OSC32KCTRL_MSK (0x1u << MCLK_APBAMASK_OSC32KCTRL_OFF)

/** \brief MCLK APBAMASK.SUPC bit offset */
#define MCLK_APBAMASK_SUPC_OFF 6u
/** \brief MCLK APBAMASK.SUPC bit mask */
#define MCLK_APBAMASK_SUPC_MSK (0x1u << MCLK_APBAMASK_SUPC_OFF)

/** \brief MCLK APBAMASK.GCLK bit offset */
#define MCLK_APBAMASK_GCLK_OFF 7u
/** \brief MCLK APBAMASK.GCLK bit mask */
#define MCLK_APBAMASK_GCLK_MSK (0x1u << MCLK_APBAMASK_GCLK_OFF)

/** \brief MCLK APBAMASK.WDT bit offset */
#define MCLK_APBAMASK_WDT_OFF 8u
/** \brief MCLK APBAMASK.WDT bit mask */
#define MCLK_APBAMASK_WDT_MSK (0x1u << MCLK_APBAMASK_WDT_OFF)

/** \brief MCLK APBAMASK.RTC bit offset */
#define MCLK_APBAMASK_RTC_OFF 9u
/** \brief MCLK APBAMASK.RTC bit mask */
#define MCLK_APBAMASK_RTC_MSK (0x1u << MCLK_APBAMASK_RTC_OFF)

/** \brief MCLK APBAMASK.EIC bit offset */
#define MCLK_APBAMASK_EIC_OFF 10u
/** \brief MCLK APBAMASK.EIC bit mask */
#define MCLK_APBAMASK_EIC_MSK (0x1u << MCLK_APBAMASK_EIC_OFF)

/** \brief MCLK APBAMASK.FREQM bit offset */
#define MCLK_APBAMASK_FREQM_OFF 11u
/** \brief MCLK APBAMASK.FREQM bit mask */
#define MCLK_APBAMASK_FREQM_MSK (0x1u << MCLK_APBAMASK_FREQM_OFF)

/** \brief MCLK APBAMASK.TSENS bit offset */
#define MCLK_APBAMASK_TSENS_OFF 12u
/** \brief MCLK APBAMASK.TSENS bit mask */
#define MCLK_APBAMASK_TSENS_MSK (0x1u << MCLK_APBAMASK_TSENS_OFF)

/**@}*/

/** \name MCLK APBBMASK register */
/**@{*/

/** \brief MCLK APBBMASK register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief PORT APBB clock enable */
		uint32_t PORT:1;
		/** \brief DSU APBB clock enable */
		uint32_t DSU:1;
		/** \brief NVMCTRL APBB clock enable */
		uint32_t NVMCTRL:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief HMATRIXHS APBB clock enable */
		uint32_t HMATRIXHS:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Reserved */
		uint32_t :8;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} mclk_apbbmask_t;

/** \brief MCLK APBBMASK register address offset */
#define MCLK_APBBMASK_OFF 0x18u

/** \brief MCLK APBBMASK register address */
#define MCLK_APBBMASK_ADDR (MCLK_ADDR + MCLK_APBBMASK_OFF)

/** \brief MCLK APBBMASK register */
#define MCLK_APBBMASK (*((volatile mclk_apbbmask_t*) MCLK_APBBMASK_ADDR))

/** \brief MCLK APBBMASK.PORT bit offset */
#define MCLK_APBBMASK_PORT_OFF 0u
/** \brief MCLK APBBMASK.PORT bit mask */
#define MCLK_APBBMASK_PORT_MSK (0x1u << MCLK_APBBMASK_PORT_OFF)

/** \brief MCLK APBBMASK.DSU bit offset */
#define MCLK_APBBMASK_DSU_OFF 1u
/** \brief MCLK APBBMASK.DSU bit mask */
#define MCLK_APBBMASK_DSU_MSK (0x1u << MCLK_APBBMASK_DSU_OFF)

/** \brief MCLK APBBMASK.NVMCTRL bit offset */
#define MCLK_APBBMASK_NVMCTRL_OFF 2u
/** \brief MCLK APBBMASK.NVMCTRL bit mask */
#define MCLK_APBBMASK_NVMCTRL_MSK (0x1u << MCLK_APBBMASK_NVMCTRL_OFF)

/** \brief MCLK APBBMASK.HMATRIXHS bit offset */
#define MCLK_APBBMASK_HMATRIXHS_OFF 5u
/** \brief MCLK APBBMASK.NVMCTRL bit mask */
#define MCLK_APBBMASK_HMATRIXHS_MSK (0x1u << MCLK_APBBMASK_HMATRIXHS_OFF)

/**@}*/

/** \name MCLK APBCMASK register */
/**@{*/

/** \brief MCLK APBCMASK register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief EVSYS APBC clock enable */
		uint32_t EVSYS:1;
		/** \brief SERCOM0 APBC clock enable */
		uint32_t SERCOM0:1;
		/** \brief SERCOM1 APBC clock enable */
		uint32_t SERCOM1:1;
		/** \brief SERCOM2 APBC clock enable */
		uint32_t SERCOM2:1;
		/** \brief SERCOM3 APBC clock enable */
		uint32_t SERCOM3:1;
		/** \brief SERCOM4 APBC clock enable */
		uint32_t SERCOM4:1;
		/** \brief SERCOM5 APBC clock enable */
		uint32_t SERCOM5:1;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief TCC0 APBC clock enable */
		uint32_t TCC0:1;
		/** \brief TCC1 APBC clock enable */
		uint32_t TCC1:1;
		/** \brief TCC2 APBC clock enable */
		uint32_t TCC2:1;
		/** \brief TC0 APBC clock enable */
		uint32_t TC0:1;
		/** \brief TC1 APBC clock enable */
		uint32_t TC1:1;
		/** \brief TC2 APBC clock enable */
		uint32_t TC2:1;
		/** \brief TC3 APBC clock enable */
		uint32_t TC3:1;
		/** \brief TC4 APBC clock enable */
		uint32_t TC4:1;
		/** \brief ADC0 APBC clock enable */
		uint32_t ADC0:1;
		/** \brief ADC1 APBC clock enable */
		uint32_t ADC1:1;
		/** \brief SDADC APBC clock enable */
		uint32_t SDADC:1;
		/** \brief AC APBC clock enable */
		uint32_t AC:1;
		/** \brief DAC APBC clock enable */
		uint32_t DAC:1;
		/** \brief PTC APBC clock enable */
		uint32_t PTC:1;
		/** \brief CCL APBC clock enable */
		uint32_t CCL:1;
		/** \brief Reserved */
		uint32_t :8;
	} B;
} mclk_apbcmask_t;

/** \brief MCLK APBCMASK register address offset */
#define MCLK_APBCMASK_OFF 0x1Cu

/** \brief MCLK APBCMASK register address */
#define MCLK_APBCMASK_ADDR (MCLK_ADDR + MCLK_APBCMASK_OFF)

/** \brief MCLK APBCMASK register */
#define MCLK_APBCMASK (*((volatile mclk_apbcmask_t*) MCLK_APBCMASK_ADDR))

/** \brief MCLK APBCMASK.EVSYS bit offset */
#define MCLK_APBCMASK_EVSYS_OFF 0u
/** \brief MCLK APBCMASK.EVSYS bit mask */
#define MCLK_APBCMASK_EVSYS_MSK (0x1u << MCLK_APBCMASK_EVSYS_OFF)

/** \brief MCLK APBCMASK.SERCOM0 bit offset */
#define MCLK_APBCMASK_SERCOM0_OFF 1u
/** \brief MCLK APBCMASK.SERCOM0 bit mask */
#define MCLK_APBCMASK_SERCOM0_MSK (0x1u << MCLK_APBCMASK_SERCOM0_OFF)

/** \brief MCLK APBCMASK.SERCOM1 bit offset */
#define MCLK_APBCMASK_SERCOM1_OFF 2u
/** \brief MCLK APBCMASK.SERCOM1 bit mask */
#define MCLK_APBCMASK_SERCOM1_MSK (0x1u << MCLK_APBCMASK_SERCOM1_OFF)

/** \brief MCLK APBCMASK.SERCOM2 bit offset */
#define MCLK_APBCMASK_SERCOM2_OFF 3u
/** \brief MCLK APBCMASK.SERCOM2 bit mask */
#define MCLK_APBCMASK_SERCOM2_MSK (0x1u << MCLK_APBCMASK_SERCOM2_OFF)

/** \brief MCLK APBCMASK.SERCOM3 bit offset */
#define MCLK_APBCMASK_SERCOM3_OFF 4u
/** \brief MCLK APBCMASK.SERCOM3 bit mask */
#define MCLK_APBCMASK_SERCOM3_MSK (0x1u << MCLK_APBCMASK_SERCOM3_OFF)

/** \brief MCLK APBCMASK.SERCOM4 bit offset */
#define MCLK_APBCMASK_SERCOM4_OFF 5u
/** \brief MCLK APBCMASK.SERCOM4 bit mask */
#define MCLK_APBCMASK_SERCOM4_MSK (0x1u << MCLK_APBCMASK_SERCOM4_OFF)

/** \brief MCLK APBCMASK.SERCOM5 bit offset */
#define MCLK_APBCMASK_SERCOM5_OFF 6u
/** \brief MCLK APBCMASK.SERCOM5 bit mask */
#define MCLK_APBCMASK_SERCOM5_MSK (0x1u << MCLK_APBCMASK_SERCOM5_OFF)

/** \brief MCLK APBCMASK.TCC0 bit offset */
#define MCLK_APBCMASK_TCC0_OFF 9u
/** \brief MCLK APBCMASK.TCC0 bit mask */
#define MCLK_APBCMASK_TCC0_MSK (0x1u << MCLK_APBCMASK_TCC0_OFF)

/** \brief MCLK APBCMASK.TCC1 bit offset */
#define MCLK_APBCMASK_TCC1_OFF 10u
/** \brief MCLK APBCMASK.TCC1 bit mask */
#define MCLK_APBCMASK_TCC1_MSK (0x1u << MCLK_APBCMASK_TCC1_OFF)

/** \brief MCLK APBCMASK.TCC2 bit offset */
#define MCLK_APBCMASK_TCC2_OFF 11u
/** \brief MCLK APBCMASK.TCC2 bit mask */
#define MCLK_APBCMASK_TCC2_MSK (0x1u << MCLK_APBCMASK_TCC2_OFF)

/** \brief MCLK APBCMASK.TC0 bit offset */
#define MCLK_APBCMASK_TC0_OFF 12u
/** \brief MCLK APBCMASK.TC0 bit mask */
#define MCLK_APBCMASK_TC0_MSK (0x1u << MCLK_APBCMASK_TC0_OFF)

/** \brief MCLK APBCMASK.TC1 bit offset */
#define MCLK_APBCMASK_TC1_OFF 13u
/** \brief MCLK APBCMASK.TC1 bit mask */
#define MCLK_APBCMASK_TC1_MSK (0x1u << MCLK_APBCMASK_TC1_OFF)

/** \brief MCLK APBCMASK.TC2 bit offset */
#define MCLK_APBCMASK_TC2_OFF 14u
/** \brief MCLK APBCMASK.TC2 bit mask */
#define MCLK_APBCMASK_TC2_MSK (0x1u << MCLK_APBCMASK_TC2_OFF)

/** \brief MCLK APBCMASK.TC3 bit offset */
#define MCLK_APBCMASK_TC3_OFF 15u
/** \brief MCLK APBCMASK.TC3 bit mask */
#define MCLK_APBCMASK_TC3_MSK (0x1u << MCLK_APBCMASK_TC3_OFF)

/** \brief MCLK APBCMASK.TC4 bit offset */
#define MCLK_APBCMASK_TC4_OFF 16u
/** \brief MCLK APBCMASK.TC4 bit mask */
#define MCLK_APBCMASK_TC4_MSK (0x1u << MCLK_APBCMASK_TC4_OFF)

/** \brief MCLK APBCMASK.ADC0 bit offset */
#define MCLK_APBCMASK_ADC0_OFF 17u
/** \brief MCLK APBCMASK.ADC0 bit mask */
#define MCLK_APBCMASK_ADC0_MSK (0x1u << MCLK_APBCMASK_ADC0_OFF)

/** \brief MCLK APBCMASK.ADC1 bit offset */
#define MCLK_APBCMASK_ADC1_OFF 18u
/** \brief MCLK APBCMASK.ADC1 bit mask */
#define MCLK_APBCMASK_ADC1_MSK (0x1u << MCLK_APBCMASK_ADC1_OFF)

/** \brief MCLK APBCMASK.SDADC bit offset */
#define MCLK_APBCMASK_SDADC_OFF 19u
/** \brief MCLK APBCMASK.SDADC bit mask */
#define MCLK_APBCMASK_SDADC_MSK (0x1u << MCLK_APBCMASK_SDADC_OFF)

/** \brief MCLK APBCMASK.AC bit offset */
#define MCLK_APBCMASK_AC_OFF 20u
/** \brief MCLK APBCMASK.AC bit mask */
#define MCLK_APBCMASK_AC_MSK (0x1u << MCLK_APBCMASK_AC_OFF)

/** \brief MCLK APBCMASK.DAC bit offset */
#define MCLK_APBCMASK_DAC_OFF 21u
/** \brief MCLK APBCMASK.DAC bit mask */
#define MCLK_APBCMASK_DAC_MSK (0x1u << MCLK_APBCMASK_DAC_OFF)

/** \brief MCLK APBCMASK.PTC bit offset */
#define MCLK_APBCMASK_PTC_OFF 22u
/** \brief MCLK APBCMASK.PTC bit mask */
#define MCLK_APBCMASK_PTC_MSK (0x1u << MCLK_APBCMASK_PTC_OFF)

/** \brief MCLK APBCMASK.CCL bit offset */
#define MCLK_APBCMASK_CCL_OFF 23u
/** \brief MCLK APBCMASK.CCL bit mask */
#define MCLK_APBCMASK_CCL_MSK (0x1u << MCLK_APBCMASK_CCL_OFF)

/**@}*/

/** \name MCLK APBDMASK register */
/**@{*/

/** \brief MCLK APBDMASK register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief TC7 APBD clock enable */
		uint32_t SERCOM6:1;
		/** \brief TC6 APBD clock enable */
		uint32_t SERCOM7:1;
		/** \brief TC5 APBD clock enable */
		uint32_t TC5:1;
		/** \brief TC6 APBD clock enable */
		uint32_t TC6:1;
		/** \brief TC7 APBD clock enable */
		uint32_t TC7:1;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief Reserved */
		uint32_t :8;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} mclk_apbdmask_t;

/** \brief MCLK APBDMASK register address offset */
#define MCLK_APBDMASK_OFF 0x20u

/** \brief MCLK APBDMASK register address */
#define MCLK_APBDMASK_ADDR (MCLK_ADDR + MCLK_APBDMASK_OFF)

/** \brief MCLK APBDMASK register */
#define MCLK_APBDMASK (*((volatile mclk_apbdmask_t*) MCLK_APBDMASK_ADDR))

/** \brief MCLK APBDMASK.SERCOM6 bit offset */
#define MCLK_APBDMASK_SERCOM6_OFF 0u
/** \brief MCLK APBDMASK.SERCOM6 bit mask */
#define MCLK_APBDMASK_SERCOM6_MSK (0x1u << MCLK_APBDMASK_SERCOM6_OFF)

/** \brief MCLK APBDMASK.SERCOM7 bit offset */
#define MCLK_APBDMASK_SERCOM7_OFF 1u
/** \brief MCLK APBDMASK.SERCOM7 bit mask */
#define MCLK_APBDMASK_SERCOM7_MSK (0x1u << MCLK_APBDMASK_SERCOM7_OFF)

/** \brief MCLK APBDMASK.TC5 bit offset */
#define MCLK_APBDMASK_TC5_OFF 2u
/** \brief MCLK APBDMASK.TC5 bit mask */
#define MCLK_APBDMASK_TC5_MSK (0x1u << MCLK_APBDMASK_TC5_OFF)

/** \brief MCLK APBDMASK.TC6 bit offset */
#define MCLK_APBDMASK_TC6_OFF 3u
/** \brief MCLK APBDMASK.TC6 bit mask */
#define MCLK_APBDMASK_TC6_MSK (0x1u << MCLK_APBDMASK_TC6_OFF)

/** \brief MCLK APBDMASK.TC7 bit offset */
#define MCLK_APBDMASK_TC7_OFF 4u
/** \brief MCLK APBDMASK.TC7 bit mask */
#define MCLK_APBDMASK_TC7_MSK (0x1u << MCLK_APBDMASK_TC7_OFF)

/**@}*/

#endif /* SAMFD_MCLK_H */
