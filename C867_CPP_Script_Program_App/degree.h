/* Rubric C. Defining an enumerated data type DegreeProgram for the degree
programs containing the data type values SECURITY, NETWORK, and
SOFTWARE.*/

#pragma once

#include <string>

enum class degreeProgramEnum { SECURITY = 0, NETWORK = 1, SOFTWARE = 2};

/* Translating the degreeProgramEnum to strings degreeProgramStrings. */
static const string degreeProgramStrings[] = { "Security", "Network", "Software" };

