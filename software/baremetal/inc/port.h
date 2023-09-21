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

#endif /* SAMFD_PORT_H */
