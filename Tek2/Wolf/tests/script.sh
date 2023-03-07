#!/bin/bash

./wolfram --rule 30 --lines 20 | cat -e > tests/got_30
./wolfram --rule 90 --lines 20 | cat -e > tests/got_90
./wolfram --rule 110 --lines 20 | cat -e > tests/got_110

./wolfram --rule 30 --lines 60 | cat -e > tests/got_30_long
./wolfram --rule 90 --lines 40 | cat -e > tests/got_90_long
./wolfram --rule 110 --lines 20 --window 20 | cat -e > tests/got_110_long

./wolfram --rule 90 --lines 20 --start 100 | cat -e > tests/got_90_start

./wolfram --rule 30 --lines 20 --move 10 | cat -e > tests/got_30_bmove
./wolfram --rule 30 --lines 20 --move -10 | cat -e > tests/got_30_bmove_bis

diff tests/expected_30 tests/got_30
diff tests/expected_90 tests/got_90
diff tests/expected_110 tests/got_110

diff tests/expected_30_long tests/got_30_long
diff tests/expected_90_long tests/got_90_long
diff tests/expected_110_long tests/got_110_long

diff tests/expected_90_start tests/got_90_start

diff tests/expected_30_bmove tests/got_30_bmove
diff tests/expected_30_bmove_bis tests/got_30_bmove_bis