execFileName="ReaderTest.out"

compileFilesList=("Reader")

compileFilesLine=""
testFileName="ReaderTest.cpp"

cd "$(pwd)/PocketReader"


for i in "${compileFilesList[@]}"; do
    compileFilesLine="$compileFilesLine src/$i.cpp"
done

echo "File in compiling: $compileFilesLine"

echo "Create executable: "
g++ -I include "tests/$testFileName" $compileFilesLine -o "build/$execFileName"


echo "Run executable: "

"./build/$execFileName"
