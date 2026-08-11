execFileName="PocketReaderTest.out"

compileFilesList=("Reader" "Book" "Library" "Storage" "BookReader" "TextLayout")

compileFilesLine=""
# testFileName="ReaderTest.cpp"
# testFileName="BookTest.cpp"
# testFileName="LibraryTest.cpp"
# testFileName="StorageTest.cpp"
# testFileName="IntegrationTest.cpp"
# testFileName="BookReaderTest.cpp"
testFileName="TextLayoutTest.cpp"

cd "$(pwd)/PocketReader"


for i in "${compileFilesList[@]}"; do
    compileFilesLine="$compileFilesLine src/$i.cpp"
done

echo "File in compiling: $compileFilesLine"

echo "Create executable: "
g++ -I include "tests/$testFileName" $compileFilesLine -o "build/$execFileName"


echo "Run executable: "

"./build/$execFileName"
