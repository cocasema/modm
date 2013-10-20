#ifndef XPCC__XILINX_SPARTAN_3
#define XPCC__XILINX_SPARTAN_3


namespace xpcc
{
/**
 * Configure an Xilinx Spartan 3 series FPGA in Slave Serial mode.
 *
 * In Slave Serial mode (M[2:0] = <1:1:1>) the configuration data is clocked
 * in using the synchronous serial interface.
 *
 * The configuration data is read from @param DataSource which must provide a
 * readPage() method.
 *
 */
template <	typename Cclk,			///< Clock output to FPGA
			typename Din,			///< Data output to FPGA
			typename ProgB,			///< ProgB output to FPGA
			typename InitB,			///< InitB input from FPGA
			typename Done,			///< Done input from FPGA. FPGA signalises end of configuration.
			typename DataSource,	///< Source of configuration data, e.g. serial external flash.
			typename Led0 = xpcc::GpioUnused,
			typename Led1 = xpcc::GpioUnused >
class XilinxSpartan3
{
public:
	static bool
	initialize();

	static bool
	configureFpga();

	static bool
	reconfigureFpga();

protected:
	static void
	displayResult(bool result);


};

}

#include "xilinx_spartan3_impl.hpp"

#endif // XPCC__XILINX_SPARTAN_3
