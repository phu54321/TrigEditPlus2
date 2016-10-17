#include <string>
#include <cstdint>

#include <packon.h>
typedef struct {
	uint32_t locid;
	uint32_t player;
	uint32_t res;
	uint16_t uid;
	uint8_t setting;
	uint8_t condtype;
	uint8_t res_setting;
	uint8_t prop;
	uint16_t dummy;
}TrigCond;
#include <packoff.h>

std::string DecodeCondition(const char* ptr) {
	auto cond = reinterpret_cast<const TrigCond*>(ptr);
	if (cond->condtype == 0x22) return "Always();";
	else return "Never();";
}
