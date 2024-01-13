
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
int
process(
	char const*	search_dir
);

int main(int argc, char* argv[]) {

	char const* const	program_name	=	argv[0];
	char const*			search_dir		=	nullptr;

	switch (argc)
	{
	case 1:
		fprintf(
			stderr
		,	"%s: search-directory not specified; use --help for usage\n"
		,	program_name
		);

		return EXIT_FAILURE;
	case 2:

		if (0 == strcmp("--help", argv[1]))
		{
			printf(
				"USAGE: %s { <search-directory> | --help }\n"
			,	program_name
			);	

			return EXIT_SUCCESS;
		}
		else
		{
			search_dir = argv[1];
		}

		break;
	default:
		fprintf(
			stderr
		,	"%s: too many arguments; use --help for usage\n"
		,	program_name
		);

		return EXIT_FAILURE;
	}

	return process(
		search_dir
	);
}

static
int
process(
	char const*	search_dir
)
{
	printf("process(search_dir=%s)\n", search_dir);

	return 0;
}


