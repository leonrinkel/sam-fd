/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/gclk.h
 * \brief     Definitions regarding GCLK registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_GCLK_H
#define SAMFD_GCLK_H

#include <stdint.h>

/** \brief GCLK registers base address */
#define GCLK_ADDR 0x40001C00u

/** \name GCLK GENCTRL register */
/**@{*/

/** \brief GCLK GENCTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Generator clock source selection */
		uint32_t SRC:5;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief Generator enable */
		uint32_t GENEN:1;
		/** \brief Improve duty cycle */
		uint32_t IDC:1;
		/** \brief Output off value */
		uint32_t OOV:1;
		/** \brief Output enable */
		uint32_t OE:1;
		/** \brief Divide selection */
		uint32_t DIVSEL:1;
		/** \brief Run in standby */
		uint32_t RUNSTDBY:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Division factor */
		uint32_t DIV:16;
	} B;
} gclk_genctrl_t;

/** \brief GCLK GENCTRL0 register address offset */
#define GCLK_GENCTRL0_OFF 0x20u
/** \brief GCLK GENCTRL1 register address offset */
#define GCLK_GENCTRL1_OFF 0x24u
/** \brief GCLK GENCTRL2 register address offset */
#define GCLK_GENCTRL2_OFF 0x28u
/** \brief GCLK GENCTRL3 register address offset */
#define GCLK_GENCTRL3_OFF 0x2Cu
/** \brief GCLK GENCTRL4 register address offset */
#define GCLK_GENCTRL4_OFF 0x30u
/** \brief GCLK GENCTRL5 register address offset */
#define GCLK_GENCTRL5_OFF 0x34u
/** \brief GCLK GENCTRL6 register address offset */
#define GCLK_GENCTRL6_OFF 0x38u
/** \brief GCLK GENCTRL7 register address offset */
#define GCLK_GENCTRL7_OFF 0x3Cu
/** \brief GCLK GENCTRL8 register address offset */
#define GCLK_GENCTRL8_OFF 0x40u

/** \brief GCLK GENCTRL0 register address */
#define GCLK_GENCTRL0_ADDR (GCLK_ADDR + GCLK_GENCTRL0_OFF)
/** \brief GCLK GENCTRL1 register address */
#define GCLK_GENCTRL1_ADDR (GCLK_ADDR + GCLK_GENCTRL1_OFF)
/** \brief GCLK GENCTRL2 register address */
#define GCLK_GENCTRL2_ADDR (GCLK_ADDR + GCLK_GENCTRL2_OFF)
/** \brief GCLK GENCTRL3 register address */
#define GCLK_GENCTRL3_ADDR (GCLK_ADDR + GCLK_GENCTRL3_OFF)
/** \brief GCLK GENCTRL4 register address */
#define GCLK_GENCTRL4_ADDR (GCLK_ADDR + GCLK_GENCTRL4_OFF)
/** \brief GCLK GENCTRL5 register address */
#define GCLK_GENCTRL5_ADDR (GCLK_ADDR + GCLK_GENCTRL5_OFF)
/** \brief GCLK GENCTRL6 register address */
#define GCLK_GENCTRL6_ADDR (GCLK_ADDR + GCLK_GENCTRL6_OFF)
/** \brief GCLK GENCTRL7 register address */
#define GCLK_GENCTRL7_ADDR (GCLK_ADDR + GCLK_GENCTRL7_OFF)
/** \brief GCLK GENCTRL8 register address */
#define GCLK_GENCTRL8_ADDR (GCLK_ADDR + GCLK_GENCTRL8_OFF)

/** \brief GCLK GENCTRL0 register */
#define GCLK_GENCTRL0 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL0_ADDR))
/** \brief GCLK GENCTRL1 register */
#define GCLK_GENCTRL1 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL1_ADDR))
/** \brief GCLK GENCTRL2 register */
#define GCLK_GENCTRL2 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL2_ADDR))
/** \brief GCLK GENCTRL3 register */
#define GCLK_GENCTRL3 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL3_ADDR))
/** \brief GCLK GENCTRL4 register */
#define GCLK_GENCTRL4 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL4_ADDR))
/** \brief GCLK GENCTRL5 register */
#define GCLK_GENCTRL5 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL5_ADDR))
/** \brief GCLK GENCTRL6 register */
#define GCLK_GENCTRL6 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL6_ADDR))
/** \brief GCLK GENCTRL7 register */
#define GCLK_GENCTRL7 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL7_ADDR))
/** \brief GCLK GENCTRL8 register */
#define GCLK_GENCTRL8 (*((volatile gclk_genctrl_t*) GCLK_GENCTRL8_ADDR))

/** \brief GCLK GENCTRL.SRC bit offset */
#define GCLK_GENCTRL_SRC_OFF 0u
/** \brief GCLK GENCTRL.SRC bit mask */
#define GCLK_GENCTRL_SRC_MSK (0x1Fu << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.GENEN bit offset */
#define GCLK_GENCTRL_GENEN_OFF 8u
/** \brief GCLK GENCTRL.GENEN bit mask */
#define GCLK_GENCTRL_GENEN_MSK (0x1u << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.IDC bit offset */
#define GCLK_GENCTRL_IDC_OFF 9u
/** \brief GCLK GENCTRL.IDC bit mask */
#define GCLK_GENCTRL_IDC_MSK (0x1u << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.OOV bit offset */
#define GCLK_GENCTRL_OOV_OFF 10u
/** \brief GCLK GENCTRL.OOV bit mask */
#define GCLK_GENCTRL_OOV_MSK (0x1u << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.OE bit offset */
#define GCLK_GENCTRL_OE_OFF 11u
/** \brief GCLK GENCTRL.OE bit mask */
#define GCLK_GENCTRL_OE_MSK (0x1u << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.DIVSEL bit offset */
#define GCLK_GENCTRL_DIVSEL_OFF 12u
/** \brief GCLK GENCTRL.DIVSEL bit mask */
#define GCLK_GENCTRL_DIVSEL_MSK (0x1u << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.RUNSTDBY bit offset */
#define GCLK_GENCTRL_RUNSTDBY_OFF 13u
/** \brief GCLK GENCTRL.RUNSTDBY bit mask */
#define GCLK_GENCTRL_RUNSTDBY_MSK (0x1u << GCLK_GENCTRL_OFF)

/** \brief GCLK GENCTRL.DIV bit offset */
#define GCLK_GENCTRL_DIV_OFF 16u
/** \brief GCLK GENCTRL.DIV bit mask */
#define GCLK_GENCTRL_DIV_MSK (0xFFFFu << GCLK_GENCTRL_OFF)

/**@}*/

/** \name GCLK PCHCTRL register */
/**@{*/

/** \brief GCLK PCHCTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Generator selection */
		uint32_t GEN:4;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Channel enable */
		uint32_t CHEN:1;
		/** \brief Write lock */
		uint32_t WRTLOCK:1;
		/** \brief Reserved */
		uint32_t :8;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} gclk_pchctrl_t;

/** \brief GCLK PCHCTRL0 register address offset */
#define GCLK_PCHCTRL0_OFF 0x080u
/** \brief GCLK PCHCTRL1 register address offset */
#define GCLK_PCHCTRL1_OFF 0x084u
/** \brief GCLK PCHCTRL2 register address offset */
#define GCLK_PCHCTRL2_OFF 0x088u
/** \brief GCLK PCHCTRL3 register address offset */
#define GCLK_PCHCTRL3_OFF 0x08Cu
/** \brief GCLK PCHCTRL4 register address offset */
#define GCLK_PCHCTRL4_OFF 0x090u
/** \brief GCLK PCHCTRL5 register address offset */
#define GCLK_PCHCTRL5_OFF 0x094u
/** \brief GCLK PCHCTRL6 register address offset */
#define GCLK_PCHCTRL6_OFF 0x098u
/** \brief GCLK PCHCTRL7 register address offset */
#define GCLK_PCHCTRL7_OFF 0x09Cu
/** \brief GCLK PCHCTRL8 register address offset */
#define GCLK_PCHCTRL8_OFF 0x0A0u
/** \brief GCLK PCHCTRL9 register address offset */
#define GCLK_PCHCTRL9_OFF 0x0A4u
/** \brief GCLK PCHCTRL10 register address offset */
#define GCLK_PCHCTRL10_OFF 0x0A8u
/** \brief GCLK PCHCTRL11 register address offset */
#define GCLK_PCHCTRL11_OFF 0x0ACu
/** \brief GCLK PCHCTRL12 register address offset */
#define GCLK_PCHCTRL12_OFF 0x0B0u
/** \brief GCLK PCHCTRL13 register address offset */
#define GCLK_PCHCTRL13_OFF 0x0B4u
/** \brief GCLK PCHCTRL14 register address offset */
#define GCLK_PCHCTRL14_OFF 0x0B8u
/** \brief GCLK PCHCTRL15 register address offset */
#define GCLK_PCHCTRL15_OFF 0x0BCu
/** \brief GCLK PCHCTRL16 register address offset */
#define GCLK_PCHCTRL16_OFF 0x0C0u
/** \brief GCLK PCHCTRL17 register address offset */
#define GCLK_PCHCTRL17_OFF 0x0C4u
/** \brief GCLK PCHCTRL18 register address offset */
#define GCLK_PCHCTRL18_OFF 0x0C8u
/** \brief GCLK PCHCTRL19 register address offset */
#define GCLK_PCHCTRL19_OFF 0x0CCu
/** \brief GCLK PCHCTRL20 register address offset */
#define GCLK_PCHCTRL20_OFF 0x0D0u
/** \brief GCLK PCHCTRL21 register address offset */
#define GCLK_PCHCTRL21_OFF 0x0D4u
/** \brief GCLK PCHCTRL22 register address offset */
#define GCLK_PCHCTRL22_OFF 0x0D8u
/** \brief GCLK PCHCTRL23 register address offset */
#define GCLK_PCHCTRL23_OFF 0x0DCu
/** \brief GCLK PCHCTRL24 register address offset */
#define GCLK_PCHCTRL24_OFF 0x0E0u
/** \brief GCLK PCHCTRL25 register address offset */
#define GCLK_PCHCTRL25_OFF 0x0E4u
/** \brief GCLK PCHCTRL26 register address offset */
#define GCLK_PCHCTRL26_OFF 0x0E8u
/** \brief GCLK PCHCTRL27 register address offset */
#define GCLK_PCHCTRL27_OFF 0x0ECu
/** \brief GCLK PCHCTRL28 register address offset */
#define GCLK_PCHCTRL28_OFF 0x0F0u
/** \brief GCLK PCHCTRL29 register address offset */
#define GCLK_PCHCTRL29_OFF 0x0F4u
/** \brief GCLK PCHCTRL30 register address offset */
#define GCLK_PCHCTRL30_OFF 0x0F8u
/** \brief GCLK PCHCTRL31 register address offset */
#define GCLK_PCHCTRL31_OFF 0x0FCu
/** \brief GCLK PCHCTRL32 register address offset */
#define GCLK_PCHCTRL32_OFF 0x100u
/** \brief GCLK PCHCTRL33 register address offset */
#define GCLK_PCHCTRL33_OFF 0x104u
/** \brief GCLK PCHCTRL34 register address offset */
#define GCLK_PCHCTRL34_OFF 0x108u
/** \brief GCLK PCHCTRL35 register address offset */
#define GCLK_PCHCTRL35_OFF 0x10Cu
/** \brief GCLK PCHCTRL36 register address offset */
#define GCLK_PCHCTRL36_OFF 0x110u
/** \brief GCLK PCHCTRL37 register address offset */
#define GCLK_PCHCTRL37_OFF 0x114u
/** \brief GCLK PCHCTRL38 register address offset */
#define GCLK_PCHCTRL38_OFF 0x118u
/** \brief GCLK PCHCTRL39 register address offset */
#define GCLK_PCHCTRL39_OFF 0x11Cu
/** \brief GCLK PCHCTRL40 register address offset */
#define GCLK_PCHCTRL40_OFF 0x120u
/** \brief GCLK PCHCTRL41 register address offset */
#define GCLK_PCHCTRL41_OFF 0x124u
/** \brief GCLK PCHCTRL42 register address offset */
#define GCLK_PCHCTRL42_OFF 0x128u
/** \brief GCLK PCHCTRL43 register address offset */
#define GCLK_PCHCTRL43_OFF 0x12Cu
/** \brief GCLK PCHCTRL44 register address offset */
#define GCLK_PCHCTRL44_OFF 0x130u
/** \brief GCLK PCHCTRL45 register address offset */
#define GCLK_PCHCTRL45_OFF 0x134u

/** \brief GCLK PCHCTRL0 register address */
#define GCLK_PCHCTRL0_ADDR (GCLK_ADDR + GCLK_PCHCTRL0_OFF)
/** \brief GCLK PCHCTRL1 register address */
#define GCLK_PCHCTRL1_ADDR (GCLK_ADDR + GCLK_PCHCTRL1_OFF)
/** \brief GCLK PCHCTRL2 register address */
#define GCLK_PCHCTRL2_ADDR (GCLK_ADDR + GCLK_PCHCTRL2_OFF)
/** \brief GCLK PCHCTRL3 register address */
#define GCLK_PCHCTRL3_ADDR (GCLK_ADDR + GCLK_PCHCTRL3_OFF)
/** \brief GCLK PCHCTRL4 register address */
#define GCLK_PCHCTRL4_ADDR (GCLK_ADDR + GCLK_PCHCTRL4_OFF)
/** \brief GCLK PCHCTRL5 register address */
#define GCLK_PCHCTRL5_ADDR (GCLK_ADDR + GCLK_PCHCTRL5_OFF)
/** \brief GCLK PCHCTRL6 register address */
#define GCLK_PCHCTRL6_ADDR (GCLK_ADDR + GCLK_PCHCTRL6_OFF)
/** \brief GCLK PCHCTRL7 register address */
#define GCLK_PCHCTRL7_ADDR (GCLK_ADDR + GCLK_PCHCTRL7_OFF)
/** \brief GCLK PCHCTRL8 register address */
#define GCLK_PCHCTRL8_ADDR (GCLK_ADDR + GCLK_PCHCTRL8_OFF)
/** \brief GCLK PCHCTRL9 register address */
#define GCLK_PCHCTRL9_ADDR (GCLK_ADDR + GCLK_PCHCTRL9_OFF)
/** \brief GCLK PCHCTRL10 register address */
#define GCLK_PCHCTRL10_ADDR (GCLK_ADDR + GCLK_PCHCTRL10_OFF)
/** \brief GCLK PCHCTRL11 register address */
#define GCLK_PCHCTRL11_ADDR (GCLK_ADDR + GCLK_PCHCTRL11_OFF)
/** \brief GCLK PCHCTRL12 register address */
#define GCLK_PCHCTRL12_ADDR (GCLK_ADDR + GCLK_PCHCTRL12_OFF)
/** \brief GCLK PCHCTRL13 register address */
#define GCLK_PCHCTRL13_ADDR (GCLK_ADDR + GCLK_PCHCTRL13_OFF)
/** \brief GCLK PCHCTRL14 register address */
#define GCLK_PCHCTRL14_ADDR (GCLK_ADDR + GCLK_PCHCTRL14_OFF)
/** \brief GCLK PCHCTRL15 register address */
#define GCLK_PCHCTRL15_ADDR (GCLK_ADDR + GCLK_PCHCTRL15_OFF)
/** \brief GCLK PCHCTRL16 register address */
#define GCLK_PCHCTRL16_ADDR (GCLK_ADDR + GCLK_PCHCTRL16_OFF)
/** \brief GCLK PCHCTRL17 register address */
#define GCLK_PCHCTRL17_ADDR (GCLK_ADDR + GCLK_PCHCTRL17_OFF)
/** \brief GCLK PCHCTRL18 register address */
#define GCLK_PCHCTRL18_ADDR (GCLK_ADDR + GCLK_PCHCTRL18_OFF)
/** \brief GCLK PCHCTRL19 register address */
#define GCLK_PCHCTRL19_ADDR (GCLK_ADDR + GCLK_PCHCTRL19_OFF)
/** \brief GCLK PCHCTRL20 register address */
#define GCLK_PCHCTRL20_ADDR (GCLK_ADDR + GCLK_PCHCTRL20_OFF)
/** \brief GCLK PCHCTRL21 register address */
#define GCLK_PCHCTRL21_ADDR (GCLK_ADDR + GCLK_PCHCTRL21_OFF)
/** \brief GCLK PCHCTRL22 register address */
#define GCLK_PCHCTRL22_ADDR (GCLK_ADDR + GCLK_PCHCTRL22_OFF)
/** \brief GCLK PCHCTRL23 register address */
#define GCLK_PCHCTRL23_ADDR (GCLK_ADDR + GCLK_PCHCTRL23_OFF)
/** \brief GCLK PCHCTRL24 register address */
#define GCLK_PCHCTRL24_ADDR (GCLK_ADDR + GCLK_PCHCTRL24_OFF)
/** \brief GCLK PCHCTRL25 register address */
#define GCLK_PCHCTRL25_ADDR (GCLK_ADDR + GCLK_PCHCTRL25_OFF)
/** \brief GCLK PCHCTRL26 register address */
#define GCLK_PCHCTRL26_ADDR (GCLK_ADDR + GCLK_PCHCTRL26_OFF)
/** \brief GCLK PCHCTRL27 register address */
#define GCLK_PCHCTRL27_ADDR (GCLK_ADDR + GCLK_PCHCTRL27_OFF)
/** \brief GCLK PCHCTRL28 register address */
#define GCLK_PCHCTRL28_ADDR (GCLK_ADDR + GCLK_PCHCTRL28_OFF)
/** \brief GCLK PCHCTRL29 register address */
#define GCLK_PCHCTRL29_ADDR (GCLK_ADDR + GCLK_PCHCTRL29_OFF)
/** \brief GCLK PCHCTRL30 register address */
#define GCLK_PCHCTRL30_ADDR (GCLK_ADDR + GCLK_PCHCTRL30_OFF)
/** \brief GCLK PCHCTRL31 register address */
#define GCLK_PCHCTRL31_ADDR (GCLK_ADDR + GCLK_PCHCTRL31_OFF)
/** \brief GCLK PCHCTRL32 register address */
#define GCLK_PCHCTRL32_ADDR (GCLK_ADDR + GCLK_PCHCTRL32_OFF)
/** \brief GCLK PCHCTRL33 register address */
#define GCLK_PCHCTRL33_ADDR (GCLK_ADDR + GCLK_PCHCTRL33_OFF)
/** \brief GCLK PCHCTRL34 register address */
#define GCLK_PCHCTRL34_ADDR (GCLK_ADDR + GCLK_PCHCTRL34_OFF)
/** \brief GCLK PCHCTRL35 register address */
#define GCLK_PCHCTRL35_ADDR (GCLK_ADDR + GCLK_PCHCTRL35_OFF)
/** \brief GCLK PCHCTRL36 register address */
#define GCLK_PCHCTRL36_ADDR (GCLK_ADDR + GCLK_PCHCTRL36_OFF)
/** \brief GCLK PCHCTRL37 register address */
#define GCLK_PCHCTRL37_ADDR (GCLK_ADDR + GCLK_PCHCTRL37_OFF)
/** \brief GCLK PCHCTRL38 register address */
#define GCLK_PCHCTRL38_ADDR (GCLK_ADDR + GCLK_PCHCTRL38_OFF)
/** \brief GCLK PCHCTRL39 register address */
#define GCLK_PCHCTRL39_ADDR (GCLK_ADDR + GCLK_PCHCTRL39_OFF)
/** \brief GCLK PCHCTRL40 register address */
#define GCLK_PCHCTRL40_ADDR (GCLK_ADDR + GCLK_PCHCTRL40_OFF)
/** \brief GCLK PCHCTRL41 register address */
#define GCLK_PCHCTRL41_ADDR (GCLK_ADDR + GCLK_PCHCTRL41_OFF)
/** \brief GCLK PCHCTRL42 register address */
#define GCLK_PCHCTRL42_ADDR (GCLK_ADDR + GCLK_PCHCTRL42_OFF)
/** \brief GCLK PCHCTRL43 register address */
#define GCLK_PCHCTRL43_ADDR (GCLK_ADDR + GCLK_PCHCTRL43_OFF)
/** \brief GCLK PCHCTRL44 register address */
#define GCLK_PCHCTRL44_ADDR (GCLK_ADDR + GCLK_PCHCTRL44_OFF)
/** \brief GCLK PCHCTRL45 register address */
#define GCLK_PCHCTRL45_ADDR (GCLK_ADDR + GCLK_PCHCTRL45_OFF)

/** \brief GCLK PCHCTRL0 register */
#define GCLK_PCHCTRL0 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL0_ADDR))
/** \brief GCLK PCHCTRL1 register */
#define GCLK_PCHCTRL1 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL1_ADDR))
/** \brief GCLK PCHCTRL2 register */
#define GCLK_PCHCTRL2 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL2_ADDR))
/** \brief GCLK PCHCTRL3 register */
#define GCLK_PCHCTRL3 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL3_ADDR))
/** \brief GCLK PCHCTRL4 register */
#define GCLK_PCHCTRL4 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL4_ADDR))
/** \brief GCLK PCHCTRL5 register */
#define GCLK_PCHCTRL5 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL5_ADDR))
/** \brief GCLK PCHCTRL6 register */
#define GCLK_PCHCTRL6 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL6_ADDR))
/** \brief GCLK PCHCTRL7 register */
#define GCLK_PCHCTRL7 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL7_ADDR))
/** \brief GCLK PCHCTRL8 register */
#define GCLK_PCHCTRL8 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL8_ADDR))
/** \brief GCLK PCHCTRL9 register */
#define GCLK_PCHCTRL9 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL9_ADDR))
/** \brief GCLK PCHCTRL10 register */
#define GCLK_PCHCTRL10 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL10_ADDR))
/** \brief GCLK PCHCTRL11 register */
#define GCLK_PCHCTRL11 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL11_ADDR))
/** \brief GCLK PCHCTRL12 register */
#define GCLK_PCHCTRL12 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL12_ADDR))
/** \brief GCLK PCHCTRL13 register */
#define GCLK_PCHCTRL13 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL13_ADDR))
/** \brief GCLK PCHCTRL14 register */
#define GCLK_PCHCTRL14 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL14_ADDR))
/** \brief GCLK PCHCTRL15 register */
#define GCLK_PCHCTRL15 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL15_ADDR))
/** \brief GCLK PCHCTRL16 register */
#define GCLK_PCHCTRL16 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL16_ADDR))
/** \brief GCLK PCHCTRL17 register */
#define GCLK_PCHCTRL17 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL17_ADDR))
/** \brief GCLK PCHCTRL18 register */
#define GCLK_PCHCTRL18 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL18_ADDR))
/** \brief GCLK PCHCTRL19 register */
#define GCLK_PCHCTRL19 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL19_ADDR))
/** \brief GCLK PCHCTRL20 register */
#define GCLK_PCHCTRL20 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL20_ADDR))
/** \brief GCLK PCHCTRL21 register */
#define GCLK_PCHCTRL21 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL21_ADDR))
/** \brief GCLK PCHCTRL22 register */
#define GCLK_PCHCTRL22 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL22_ADDR))
/** \brief GCLK PCHCTRL23 register */
#define GCLK_PCHCTRL23 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL23_ADDR))
/** \brief GCLK PCHCTRL24 register */
#define GCLK_PCHCTRL24 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL24_ADDR))
/** \brief GCLK PCHCTRL25 register */
#define GCLK_PCHCTRL25 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL25_ADDR))
/** \brief GCLK PCHCTRL26 register */
#define GCLK_PCHCTRL26 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL26_ADDR))
/** \brief GCLK PCHCTRL27 register */
#define GCLK_PCHCTRL27 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL27_ADDR))
/** \brief GCLK PCHCTRL28 register */
#define GCLK_PCHCTRL28 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL28_ADDR))
/** \brief GCLK PCHCTRL29 register */
#define GCLK_PCHCTRL29 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL29_ADDR))
/** \brief GCLK PCHCTRL30 register */
#define GCLK_PCHCTRL30 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL30_ADDR))
/** \brief GCLK PCHCTRL31 register */
#define GCLK_PCHCTRL31 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL31_ADDR))
/** \brief GCLK PCHCTRL32 register */
#define GCLK_PCHCTRL32 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL32_ADDR))
/** \brief GCLK PCHCTRL33 register */
#define GCLK_PCHCTRL33 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL33_ADDR))
/** \brief GCLK PCHCTRL34 register */
#define GCLK_PCHCTRL34 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL34_ADDR))
/** \brief GCLK PCHCTRL35 register */
#define GCLK_PCHCTRL35 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL35_ADDR))
/** \brief GCLK PCHCTRL36 register */
#define GCLK_PCHCTRL36 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL36_ADDR))
/** \brief GCLK PCHCTRL37 register */
#define GCLK_PCHCTRL37 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL37_ADDR))
/** \brief GCLK PCHCTRL38 register */
#define GCLK_PCHCTRL38 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL38_ADDR))
/** \brief GCLK PCHCTRL39 register */
#define GCLK_PCHCTRL39 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL39_ADDR))
/** \brief GCLK PCHCTRL40 register */
#define GCLK_PCHCTRL40 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL40_ADDR))
/** \brief GCLK PCHCTRL41 register */
#define GCLK_PCHCTRL41 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL41_ADDR))
/** \brief GCLK PCHCTRL42 register */
#define GCLK_PCHCTRL42 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL42_ADDR))
/** \brief GCLK PCHCTRL43 register */
#define GCLK_PCHCTRL43 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL43_ADDR))
/** \brief GCLK PCHCTRL44 register */
#define GCLK_PCHCTRL44 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL44_ADDR))
/** \brief GCLK PCHCTRL45 register */
#define GCLK_PCHCTRL45 (*((volatile gclk_pchctrl_t*) GCLK_PCHCTRL45_ADDR))

/** \brief GCLK PCHCTRL.GEN bit offset */
#define GCLK_PCHCTRL_GEN_OFF 0u
/** \brief GCLK PCHCTRL.GEN bit mask */
#define GCLK_PCHCTRL_GEN_MSK (0xFu << GCLK_PCHCTRL_GEN_OFF)

/** \brief GCLK PCHCTRL.GEN bit offset */
#define GCLK_PCHCTRL_CHEN_OFF 6u
/** \brief GCLK PCHCTRL.CHEN bit mask */
#define GCLK_PCHCTRL_CHEN_MSK (0x1u << GCLK_PCHCTRL_CHEN_OFF)

/** \brief GCLK PCHCTRL.GEN bit offset */
#define GCLK_PCHCTRL_WRTLOCK_OFF 7u
/** \brief GCLK PCHCTRL.WRTLOCK bit mask */
#define GCLK_PCHCTRL_WRTLOCK_MSK (0x1u << GCLK_PCHCTRL_WRTLOCK_OFF)

/**@}*/

#endif /* SAMFD_GCLK_H */
