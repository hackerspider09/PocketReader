execFileName="PocketReader.out"

cd $(pwd)

echo "Create executable: "
g++ PocketReader/src/main.cpp -o "$execFileName"


echo "Run executable: "

./"$execFileName"
