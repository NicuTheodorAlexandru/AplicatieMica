#include "IdGenerator.h"

unsigned int IdGenerator::GenerateId()
{
	return rand() + 1;
}