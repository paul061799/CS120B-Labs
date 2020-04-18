# Test file for "Lab4_StateMachines"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly,
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below
#Test SM initialization
test "PINA: 0x00 => PORTC: 0x07, state: Init"
setPINA 0x00
continue 5
expectPORTC 0x07
expect state Init
checkResult

#Test A0 Button Press
test "PINA: 0x00, 0x01 => PORTC: 0x08, state: Press0_Release1"
setPINA 0x00
continue 5
setPINA 0x01
continue 5
expectPORTC 0x08
expect state Press0_Release1
checkResult

#Test A1 Button Press
test "PINA: 0x00, 0x02 => PORTC: 0x06, state: Press1_Release0"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
expectPORTC 0x06
expect state Press1_Release0
checkResult

#Test A0 => A1
test "PINA: 0x00, 0x01, 0x02 => PORTC: 0x07, state: Press1_Release0"
setPINA 0x00
continue 5
setPINA 0x01
continue 5
setPINA 0x02
continue 5
expectPORTC 0x07
expect state Press1_Release0
checkResult

#Test A1 => A0
test "PINA: 0x00, 0x02, 0x01 => PORTC: 0x07, state: Press0_Release1"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
setPINA 0x01
continue 5
expectPORTC 0x06
expect state Press0_Release1
checkResult

#Test A0 => A1A0
test "PINA: 0x00, 0x01, 0x03 => PORTC: 0x07, state: Press01"
setPINA 0x00
continue 5
setPINA 0x01
continue 5
setPINA 0x03
continue 5
expectPORTC 0x07
expect state Press01
checkResult

#Test A1 => A1A0
test "PINA: 0x00, 0x02, 0x03 => PORTC: 0x07, state: Press01"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
setPINA 0x03
continue 5
setPINA 0x01
expectPORTC 0x07
expect state Press01
checkResult

#Test A1A0 => A0
test "PINA: 0x00, 0x02, 0x03, 0x01 => PORTC: 0x07, state: Press0_Release1"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
setPINA 0x03
continue 5
setPINA 0x01
continue 5
expectPORTC 0x07
expect state Press0_Release1
checkResult

#Test A1A0 => A1
test "PINA: 0x00, 0x02, 0x03, 0x02 => PORTC: 0x07, state: Press1_Release0"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
setPINA 0x03
continue 5
setPINA 0x02
continue 5
expectPORTC 0x07
expect state Press1_Release0
checkResult

#Test A1A0 => Reset
test "PINA: 0x00, 0x02, 0x03, 0x00 => PORTC: 0x00, state: Init"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
setPINA 0x03
continue 5
setPINA 0x00
continue 5
expectPORTC 0x00
expect state Init
checkResult

#Test A0 => Reset
test "PINA: 0x00, 0x01, 0x00 => PORTC: 0x00, state: Init"
setPINA 0x00
continue 5
setPINA 0x01
continue 5
setPINA 0x00
continue 5
expectPORTC 0x00
expect state Init
checkResult

#Test A1 => Reset
test "PINA: 0x00, 0x02, 0x00 => PORTC: 0x00, state: Init"
setPINA 0x00
continue 5
setPINA 0x02
continue 5
setPINA 0x00
continue 5
expectPORTC 0x00
expect state Init
checkResult
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
