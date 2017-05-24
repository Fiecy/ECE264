#include <stdlib.h>
#include "mintf.h"

int main(int argc, char *argv[]) {

	int a = 163;
	float b = 0.264;
	char *ece = "ECE264";
	// Test 00: empty test
	// Expect: ""
	
	// Test 01: empty string
	mintf("");
	// Expect: ""
	
	// Test 02: string without '%'
	mintf("HelloWorld");
	// Expect: "HelloWorld"
	
	// Test 03: %d integer
	mintf("a = %d", a);
	// Expect: "a = 163"

	// Test 04: %x integer
	mintf("Hex a = %x", a);
	// Expect: "Hex a = 0xa3"

	// Test 05: %b integer
	mintf("Bi a = %b", a);
	// Expect: "Bi a = 0b10100011"

	// Test 06: %$ float or double
	mintf("Price b = %$", b);
	// Expect: "Price b = $0.26"

	// Test 07: %s string
	mintf("%s", ece);
	// Expect: "ECE264"

	// Test 08: %c character
	mintf("%c%c%c264", 'E', 'C', 'E');
	// Expect: "ECE264"
	
	// Test 09: %% percent sign
	mintf("drop rate is 100%%!");
	// Expect: "drop rate is 100%!"
	
	// Test 10: all combined together
	mintf("HelloWorld, drop rate of %s is %b%%! Hail %c%c%c %x%d!", ece, 4, 'E', 'C', 'E', 38, 4);
	// Expect: "HelloWorld, drop rate of ECE264 is 0b100%! Hail ECE 0x264!"
}
