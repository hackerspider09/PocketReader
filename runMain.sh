execFileName="PocketReader.out"

cd $(pwd)

echo "Create executable: "
g++ -I PocketReader/include PocketReader/src/main.cpp -o "$execFileName"


echo "Run executable: "

./"$execFileName"
