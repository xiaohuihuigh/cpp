find . -name '*.exe' -exec rm -rf {} \; 
find . -name '*.o' -exec rm -rf {} \; 
find . -executable -exec rm -v {} \;
