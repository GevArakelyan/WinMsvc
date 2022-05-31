#pragma once

#include "catch.hpp"

typedef std::pair<std::vector<std::string>, unsigned> MultipleStringsToValuePair;

class StringsToValueGenerator : 
	public Catch::Generators::IGenerator<std::pair<std::string, unsigned>> {
	
	int m_index;
	std::vector<std::pair<std::string, unsigned>> m_values;

public:
	StringsToValueGenerator(std::vector<MultipleStringsToValuePair> values) {
		m_index = 0;
		for (auto input : values) {
			for (auto str : input.first) {
				m_values.push_back({ str, input.second });
			}
		}
	}

	std::pair<std::string, unsigned> const& get() const override {
		return m_values[m_index];
	}

	bool next() override {
		return ++m_index < m_values.size();
	}
};

Catch::Generators::GeneratorWrapper<std::pair<std::string, unsigned>> string2value(std::vector<MultipleStringsToValuePair> values) {
	return Catch::Generators::GeneratorWrapper<std::pair<std::string, unsigned>>(
		std::unique_ptr<Catch::Generators::IGenerator<std::pair<std::string, unsigned>>>(new StringsToValueGenerator(values))
		);
}
