#include "stdafx.h"
#include "TheMovieDbDataFactory.h"
#include "SettableMovieData.h"
#include "../3rdParty/Include/rapidjson/document.h"
#include "ErrorParsingMovieDataException.h"


TheMovieDbDataFactory::TheMovieDbDataFactory()
{
}


TheMovieDbDataFactory::~TheMovieDbDataFactory()
{
}

std::shared_ptr<MovieData> TheMovieDbDataFactory::CreateFromJson(const std::string& jsonString) const
{
	try
	{
		rapidjson::Document jsonDocument;
		jsonDocument.Parse(jsonString.c_str());
		if (!jsonDocument.IsObject())
		{
			throw ErrorParsingMovieDataException();
		}

		auto imdbId = jsonDocument["imdb_id"].GetString();
		auto title = jsonDocument["title"].GetString();
		auto plot = jsonDocument["overview"].GetString();
		auto lengthMin = jsonDocument["runtime"].GetUint();

		auto result = std::make_shared<SettableMovieData>();
		result->SetImdbId(imdbId);
		result->SetTitle(title);
		result->SetPlot(plot);
		result->SetLengthMin(lengthMin);

		return result;
	}
	catch (...)
	{
		throw ErrorParsingMovieDataException();
	}
}