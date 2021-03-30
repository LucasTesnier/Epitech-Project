#!/bin/bash
#test_fonctionnel

export diff=0;
export compress_size=0;
export uncompress_size=0;
export diff_size=0;
./../antman/antman ../tests/assets/file_one_4 0 > temp_file
./../giantman/giantman ../tests/temp_file > temp_file_two
diff=`cmp ./assets/file_one_4 temp_file_two`
echo $diff
compress_size=`stat -c "%s" temp_file`
uncompress_size=`stat -c "%s" ../tests/assets/file_one_4`
diff_size=$(echo "($compress_size / $uncompress_size) * 100" |bc -l)
printf 'The file was compressed and reduced to %.0f%% of its original file\n' $diff_size
