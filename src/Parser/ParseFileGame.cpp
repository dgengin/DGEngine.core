#include "ParseFileGame.h"
#include "Json/JsonUtils.h"
#include "ParseFile.h"
#include "Parser/Game/ParseLevel.h"
#include "Utils/ParseUtils.h"
#include "Utils/Utils.h"

namespace Parser
{
	using namespace rapidjson;

	void parseDocumentGameElem(Game& game, uint16_t nameHash16, const Value& elem,
		ReplaceVars& replaceVars, MemoryPoolAllocator<CrtAllocator>& allocator)
	{
		switch (nameHash16)
		{
		case str2int16("level"): {
			if (elem.IsArray() == false) {
				parseLevel(game, elem);
			}
			else {
				for (const auto& val : elem) {
					parseDocumentElemHelper(game, nameHash16, val, replaceVars, allocator);
				}
			}
			break;
		}
		}
	}
}
