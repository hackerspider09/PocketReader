execFileName="PocketReader.out"

compileFilesList=("main" "Reader" "Book" "Library" "Storage" "TextLayout")

compileFilesLine=""

cd "$(pwd)/PocketReader"


for i in "${compileFilesList[@]}"; do
    compileFilesLine="$compileFilesLine src/$i.cpp"
done

echo "File in compiling: $compileFilesLine"

echo "Create executable: "
g++ -I include $compileFilesLine -o "build/$execFileName"


echo "Run executable: "

"./build/$execFileName"
