
#include <recls/recls.hpp>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

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
	using recls::search_sequence;

	printf("process(search_dir=%s)\n", search_dir);

	auto const recls_flags =
		recls::RECLS_F_LINK_COUNT |
		recls::RECLS_F_NODE_INDEX |
		recls::RECLS_F_NO_FOLLOW_LINKS |
		recls::FILES |
		recls::RECURSIVE
		;

	search_sequence	files(search_dir,"*", recls_flags);

	std::map<
		std::pair<
			std::size_t
		,	recls::recls_uint64_t
		>
     ,	std::vector<std::string>
     >	m;

	for (auto i = files.begin(); files.end() != i; ++i)
	{
		auto entry = *i;

#if 0
		// example filtering: hide readonly
		if (entry.is_readonly())
		{
			continue;
		}
#endif

		// filtering: only care about files
		if (entry.is_directory() || entry.is_link())
		{
			continue;
		}

		if (entry.num_links() < 2)
		{
			continue;
		}

		/*
		std::pair<stlsoft::size_type,recls::recls_uint64_t> id;
		id.first = entry.device_id();
		id.second = entry.node_index();
		 */
		auto id = std::make_pair(entry.device_id(), entry.node_index());

		auto j = m.find(id);

		if (m.end() == j)
		{
			m.insert(std::make_pair(id, std::vector<std::string>{ entry.get_directory_path() + entry.get_file()}));
		}
		else
		{
			(*j).second.push_back(entry.get_directory_path() + entry.get_file());
		}

		std::cout
//			<< '\t'
//			<< entry
//			<< '\t'
//			<< entry.get_file_size() << " byte(s)"
//			<< '\t'
//			<< entry.num_links() << " link(s)"
//			<< '\t'
//			<< entry.device_id() << '/' << entry.node_index()
			<< std::endl;
	}

	for (auto i = m.begin(); m.end() != i; ++i)
	{
		auto entries = (*i).second;

		std::sort(entries.begin(), entries.end());

		auto const& surnames = (*i).second;

		std::cout
			<< (*i).first.first << '/' << (*i).first.second
			<< " -> "
			<< std::endl;

		for (auto j = entries.begin(); entries.end() != j; ++j)
		{
			auto const& entry = *j;

			std::cout
				<< '\t'
				<< entry
				<< std::endl;
		}
	}

	return EXIT_SUCCESS;
}


