/* ************************
unit_tests.cpp
CSC499 Spring 2020
Dusty Miller - V00160288
Supervisor: Dr. Sean Chester
************************ */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <string>
#include <iostream>
#include "CSVParser.hpp"

TEST_CASE("basic ingestion - sample data"){
	constexpr unsigned char DELIM {','};
	std::string filename {"census_2000_sample_places_sample_dimensions.csv"};
	std::string header {"SE_T001_001"};
	constexpr uint32_t header_row_index {1};
	constexpr uint32_t first_data_row_index {2};
	CSVParser t1 {filename, DELIM};
	SECTION("Errors opening files or finding headers throw exceptions") {
		CHECK(true);
		// If file does not exist, exception should be thrown
		std::string bad_filename {"not_a_filename.aaa"};
		CHECK_THROWS_AS((CSVParser {bad_filename, DELIM}), std::runtime_error);

		// If header is not found in the row specified, 
		// an exception should be thrown
		std::string bad_header {"not_a_header"};
		uint32_t num_segments {5};
//		ColumnData<uint64_t> temp_cd{};
		CHECK_THROWS_AS(t1.makeSegments<uint64_t>(
			bad_header, header_row_index, first_data_row_index, num_segments),
			std::runtime_error);
	}
}
