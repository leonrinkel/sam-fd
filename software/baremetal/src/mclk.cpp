/**
 * \file   src/mclk.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of stuff related to the main clock controller.
 */

#include "mclk.hpp"

const volatile struct mclk::ahbmask* mclk::ahbmask_ro(void) const
{
	return ((const volatile struct mclk::ahbmask*)
		(_base_address + _ahbmask_register_offset));
}

volatile struct mclk::ahbmask* mclk::ahbmask_rw(void)
{
	return ((volatile struct mclk::ahbmask*)
		(_base_address + _ahbmask_register_offset));
}

const volatile struct mclk::apbamask* mclk::apbamask_ro(void) const
{
	return ((const volatile struct mclk::apbamask*)
		(_base_address + _apbamask_register_offset));
}

volatile struct mclk::apbamask* mclk::apbamask_rw(void)
{
	return ((volatile struct mclk::apbamask*)
		(_base_address + _apbamask_register_offset));
}

const volatile struct mclk::apbbmask* mclk::apbbmask_ro(void) const
{
	return ((const volatile struct mclk::apbbmask*)
		(_base_address + _apbbmask_register_offset));
}

volatile struct mclk::apbbmask* mclk::apbbmask_rw(void)
{
	return ((volatile struct mclk::apbbmask*)
		(_base_address + _apbbmask_register_offset));
}

const volatile struct mclk::apbcmask* mclk::apbcmask_ro(void) const
{
	return ((const volatile struct mclk::apbcmask*)
		(_base_address + _apbcmask_register_offset));
}

volatile struct mclk::apbcmask* mclk::apbcmask_rw(void)
{
	return ((volatile struct mclk::apbcmask*)
		(_base_address + _apbcmask_register_offset));
}

mclk::mclk(struct mclk::initializer init)
	: _base_address(init.base_address)
{
}

#define MCLK_GET_ENABLE(X, Y)             \
	case mclk::peripheral::X:             \
	{                                     \
		return (Y) ?                      \
			mclk::clock_enable::enabled : \
			mclk::clock_enable::stopped;  \
	}                                     \

enum mclk::clock_enable mclk::get_peripheral_clock_enable(
	enum mclk::peripheral p) const
{
	switch (p)
	{
		/* Peripherals of the AHB bus matrix. */
		MCLK_GET_ENABLE(ahb_apba     , ahbmask_ro()->apba     )
		MCLK_GET_ENABLE(ahb_apbb     , ahbmask_ro()->apbb     )
		MCLK_GET_ENABLE(ahb_apbc     , ahbmask_ro()->apbc     )
		MCLK_GET_ENABLE(ahb_dsu      , ahbmask_ro()->dsu      )
		MCLK_GET_ENABLE(ahb_hmatrixhs, ahbmask_ro()->hmatrixhs)
		MCLK_GET_ENABLE(ahb_nvmctrl  , ahbmask_ro()->nvmctrl  )
		MCLK_GET_ENABLE(ahb_hsram    , ahbmask_ro()->hsram    )
		MCLK_GET_ENABLE(ahb_dmac     , ahbmask_ro()->dmac     )
		MCLK_GET_ENABLE(ahb_can0     , ahbmask_ro()->can0     )
		MCLK_GET_ENABLE(ahb_pac      , ahbmask_ro()->pac      )
		MCLK_GET_ENABLE(ahb_divas    , ahbmask_ro()->divas    )

		/* Peripherals of the AHB-APB bridge A. */
		MCLK_GET_ENABLE(apba_pac       , apbamask_ro()->pac       )
		MCLK_GET_ENABLE(apba_pm        , apbamask_ro()->pm        )
		MCLK_GET_ENABLE(apba_mclk      , apbamask_ro()->mclk      )
		MCLK_GET_ENABLE(apba_rstc      , apbamask_ro()->rstc      )
		MCLK_GET_ENABLE(apba_oscctrl   , apbamask_ro()->oscctrl   )
		MCLK_GET_ENABLE(apba_osc32kctrl, apbamask_ro()->osc32kctrl)
		MCLK_GET_ENABLE(apba_supc      , apbamask_ro()->supc      )
		MCLK_GET_ENABLE(apba_gclk      , apbamask_ro()->gclk      )
		MCLK_GET_ENABLE(apba_wdt       , apbamask_ro()->wdt       )
		MCLK_GET_ENABLE(apba_rtc       , apbamask_ro()->rtc       )
		MCLK_GET_ENABLE(apba_eic       , apbamask_ro()->eic       )
		MCLK_GET_ENABLE(apba_freqm     , apbamask_ro()->freqm     )
		MCLK_GET_ENABLE(apba_tsens     , apbamask_ro()->tsens     )

		/* Peripherals of the AHB-APB bridge B. */
		MCLK_GET_ENABLE(apbb_port     , apbbmask_ro()->port     )
		MCLK_GET_ENABLE(apbb_dsu      , apbbmask_ro()->dsu      )
		MCLK_GET_ENABLE(apbb_nvmctrl  , apbbmask_ro()->nvmctrl  )
		MCLK_GET_ENABLE(apbb_hmatrixhs, apbbmask_ro()->hmatrixhs)

		/* Peripherals of the AHB-APB bridge C. */
		MCLK_GET_ENABLE(apbc_evsys  , apbcmask_ro()->evsys  )
		MCLK_GET_ENABLE(apbc_sercom0, apbcmask_ro()->sercom0)
		MCLK_GET_ENABLE(apbc_sercom1, apbcmask_ro()->sercom1)
		MCLK_GET_ENABLE(apbc_sercom2, apbcmask_ro()->sercom2)
		MCLK_GET_ENABLE(apbc_sercom3, apbcmask_ro()->sercom3)
		MCLK_GET_ENABLE(apbc_tcc0   , apbcmask_ro()->tcc0   )
		MCLK_GET_ENABLE(apbc_tcc1   , apbcmask_ro()->tcc1   )
		MCLK_GET_ENABLE(apbc_tcc2   , apbcmask_ro()->tcc2   )
		MCLK_GET_ENABLE(apbc_tc0    , apbcmask_ro()->tc0    )
		MCLK_GET_ENABLE(apbc_tc1    , apbcmask_ro()->tc1    )
		MCLK_GET_ENABLE(apbc_tc2    , apbcmask_ro()->tc2    )
		MCLK_GET_ENABLE(apbc_tc3    , apbcmask_ro()->tc3    )
		MCLK_GET_ENABLE(apbc_tc4    , apbcmask_ro()->tc4    )
		MCLK_GET_ENABLE(apbc_adc0   , apbcmask_ro()->adc0   )
		MCLK_GET_ENABLE(apbc_adc1   , apbcmask_ro()->adc1   )
		MCLK_GET_ENABLE(apbc_sdadc  , apbcmask_ro()->sdadc  )
		MCLK_GET_ENABLE(apbc_ac     , apbcmask_ro()->ac     )
		MCLK_GET_ENABLE(apbc_dac    , apbcmask_ro()->dac    )
		MCLK_GET_ENABLE(apbc_ptc    , apbcmask_ro()->ptc    )
		MCLK_GET_ENABLE(apbc_ccl    , apbcmask_ro()->ccl    )

		default: return mclk::clock_enable::stopped;
	}
}

#define MCLK_SET_ENABLE(X, Y)                   \
	case mclk::peripheral::X:                   \
	{                                           \
		Y = (e == mclk::clock_enable::enabled); \
		break;                                  \
	}                                           \

void mclk::set_peripheral_clock_enable(
	enum mclk::peripheral p, enum mclk::clock_enable e)
{
	switch (p)
	{
		/* Peripherals of the AHB bus matrix. */
		MCLK_SET_ENABLE(ahb_apba     , ahbmask_rw()->apba     )
		MCLK_SET_ENABLE(ahb_apbb     , ahbmask_rw()->apbb     )
		MCLK_SET_ENABLE(ahb_apbc     , ahbmask_rw()->apbc     )
		MCLK_SET_ENABLE(ahb_dsu      , ahbmask_rw()->dsu      )
		MCLK_SET_ENABLE(ahb_hmatrixhs, ahbmask_rw()->hmatrixhs)
		MCLK_SET_ENABLE(ahb_nvmctrl  , ahbmask_rw()->nvmctrl  )
		MCLK_SET_ENABLE(ahb_hsram    , ahbmask_rw()->hsram    )
		MCLK_SET_ENABLE(ahb_dmac     , ahbmask_rw()->dmac     )
		MCLK_SET_ENABLE(ahb_can0     , ahbmask_rw()->can0     )
		MCLK_SET_ENABLE(ahb_pac      , ahbmask_rw()->pac      )
		MCLK_SET_ENABLE(ahb_divas    , ahbmask_rw()->divas    )

		/* Peripherals of the AHB-APB bridge A. */
		MCLK_SET_ENABLE(apba_pac       , apbamask_rw()->pac       )
		MCLK_SET_ENABLE(apba_pm        , apbamask_rw()->pm        )
		MCLK_SET_ENABLE(apba_mclk      , apbamask_rw()->mclk      )
		MCLK_SET_ENABLE(apba_rstc      , apbamask_rw()->rstc      )
		MCLK_SET_ENABLE(apba_oscctrl   , apbamask_rw()->oscctrl   )
		MCLK_SET_ENABLE(apba_osc32kctrl, apbamask_rw()->osc32kctrl)
		MCLK_SET_ENABLE(apba_supc      , apbamask_rw()->supc      )
		MCLK_SET_ENABLE(apba_gclk      , apbamask_rw()->gclk      )
		MCLK_SET_ENABLE(apba_wdt       , apbamask_rw()->wdt       )
		MCLK_SET_ENABLE(apba_rtc       , apbamask_rw()->rtc       )
		MCLK_SET_ENABLE(apba_eic       , apbamask_rw()->eic       )
		MCLK_SET_ENABLE(apba_freqm     , apbamask_rw()->freqm     )
		MCLK_SET_ENABLE(apba_tsens     , apbamask_rw()->tsens     )

		/* Peripherals of the AHB-APB bridge B. */
		MCLK_SET_ENABLE(apbb_port     , apbbmask_rw()->port     )
		MCLK_SET_ENABLE(apbb_dsu      , apbbmask_rw()->dsu      )
		MCLK_SET_ENABLE(apbb_nvmctrl  , apbbmask_rw()->nvmctrl  )
		MCLK_SET_ENABLE(apbb_hmatrixhs, apbbmask_rw()->hmatrixhs)

		/* Peripherals of the AHB-APB bridge C. */
		MCLK_SET_ENABLE(apbc_evsys  , apbcmask_rw()->evsys  )
		MCLK_SET_ENABLE(apbc_sercom0, apbcmask_rw()->sercom0)
		MCLK_SET_ENABLE(apbc_sercom1, apbcmask_rw()->sercom1)
		MCLK_SET_ENABLE(apbc_sercom2, apbcmask_rw()->sercom2)
		MCLK_SET_ENABLE(apbc_sercom3, apbcmask_rw()->sercom3)
		MCLK_SET_ENABLE(apbc_tcc0   , apbcmask_rw()->tcc0   )
		MCLK_SET_ENABLE(apbc_tcc1   , apbcmask_rw()->tcc1   )
		MCLK_SET_ENABLE(apbc_tcc2   , apbcmask_rw()->tcc2   )
		MCLK_SET_ENABLE(apbc_tc0    , apbcmask_rw()->tc0    )
		MCLK_SET_ENABLE(apbc_tc1    , apbcmask_rw()->tc1    )
		MCLK_SET_ENABLE(apbc_tc2    , apbcmask_rw()->tc2    )
		MCLK_SET_ENABLE(apbc_tc3    , apbcmask_rw()->tc3    )
		MCLK_SET_ENABLE(apbc_tc4    , apbcmask_rw()->tc4    )
		MCLK_SET_ENABLE(apbc_adc0   , apbcmask_rw()->adc0   )
		MCLK_SET_ENABLE(apbc_adc1   , apbcmask_rw()->adc1   )
		MCLK_SET_ENABLE(apbc_sdadc  , apbcmask_rw()->sdadc  )
		MCLK_SET_ENABLE(apbc_ac     , apbcmask_rw()->ac     )
		MCLK_SET_ENABLE(apbc_dac    , apbcmask_rw()->dac    )
		MCLK_SET_ENABLE(apbc_ptc    , apbcmask_rw()->ptc    )
		MCLK_SET_ENABLE(apbc_ccl    , apbcmask_rw()->ccl    )
	}
}

void mclk::enable_peripheral_clock(enum mclk::peripheral p)
{
	set_peripheral_clock_enable(p, mclk::clock_enable::enabled);
}

void mclk::stop_peripheral_clock(enum mclk::peripheral p)
{
	set_peripheral_clock_enable(p, mclk::clock_enable::stopped);
}
