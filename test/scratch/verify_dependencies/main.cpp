
#include <stlsoft/stlsoft.h>

#include <recls/recls.h>

#include <xtests/xtests.h>

#include <WilliamsCRC/WilliamsCRC.h>

#include <iomanip>
#include <iostream>

#include <stddef.h>


int main(int argc, char* argv[])
{
	// verify STLSoft
	{
		std::cout
			<< "STLSoft:"
			<< std::endl
			<< "\t" << "_STLSOFT_VER: 0x" << std::setfill('0') << std::hex << std::setw(8) << _STLSOFT_VER
			<< std::endl;
	}

	std::cout << std::endl;


	// verify xTests
	{
		int retCode = EXIT_SUCCESS;
	    int verbosity;

	    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

		std::cout
			<< "xTests:"
			<< std::endl
			<< "\t" << "_XTESTS_VER: 0x" << std::setfill('0') << std::hex << std::setw(8) << _XTESTS_VER
			<< std::endl
			<< "\t" << "verbosity: " << verbosity
			<< std::endl;
	}

	std::cout << std::endl;


	// verify recls
	{
		using recls::recls_root_t;
		using recls::Recls_GetRoots;

		recls_root_t	roots[10];
		size_t			num_roots = Recls_GetRoots(&roots[0], STLSOFT_NUM_ELEMENTS(roots));

		std::cout
			<< "recls:"
			<< std::endl
			<< "\t" << "RECLS_VER: 0x" << std::setfill('0') << std::hex << std::setw(8) << RECLS_VER
			<< std::endl
			<< "\t" << num_roots << " root(s): "
			<< std::endl
			;

		for (size_t i = 0; i != num_roots; ++i)
		{
			std::cout << "\t\troot-" << i << "='" << roots[i].name << "'" << std::endl;
		}
	}

	std::cout << std::endl;


	// verify WilliamsCRC
	{
		int r = WilliamsCRC_Init();

		if (0 == r)
		{
			const unsigned char bytes[] = { 0, 1, 2, 3, 4 };

			crc_result_t		result;

			r = WilliamsCRC_CalculateBlockCrc(&bytes[0], sizeof(bytes), 32, 0, &result);

			std::cout
				<< "WilliamsCRC:"
				<< std::endl
				<< "\t" << "SYNSOFT_WILLIAMSCRC_VER: 0x" << std::setfill('0') << std::hex << std::setw(8) << SYNSOFT_WILLIAMSCRC_VER
				<< std::endl
				<< "\t" << "32-bit CRC of `bytes`: 0x" << std::setfill('0') << std::hex << std::setw(8) << result
				<< std::endl;


			WilliamsCRC_Uninit();
		}
	}

	std::cout << std::endl;


	return 0;
}



