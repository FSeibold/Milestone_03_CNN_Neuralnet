#include <QCoreApplication>
#include <iostream>
#include <vector>



class Channel{
public:

    Channel(){}
    ~Channel(){}

    std::vector<std::vector<std::vector<std::vector<int>>>> matrix;
    int zeile, spalte, k2, l2;

    int setMatrix(int row, int col, int k, int l, std::vector<std::vector<std::vector<std::vector<int>>>> vec){
        matrix = vec;
        zeile = row;
        spalte = col;
        k2 = k;
        l2 = l;
    }

    void printMatrix()
    {
        for(int i = 0; i < zeile; i++){
            for(int j = 0; j < spalte; j++){
                for(int k = 0; k < k2; k++){
                    for(int l = 0; l < l2; l++){
                        std::cout << "|" << matrix[i][j][k][l];
                    }
                }
            }
            std::cout << "\n";
        }
    }
};


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);    
    Channel c;
    std::cout << "\nFunktionseingang: \n";

    const int row = 28, col = 3, k1 = 3, l1 = 3;
    int random;

    std::vector<std::vector<std::vector<std::vector<int>>>> vec(row, ((col, std::vector<std::vector<std::vector<int>>>(k1,
                                                                                       std::vector<std::vector<int>>(l1)))));
    std::cout << "\nKernel: " << row << " x " << col << "x" << k1 << "x" << l1 << "-Matrix:\n";

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            std::vector<std::vector<int>> cTemp(col, std::vector<int>(k1));
            vec[i][j] = cTemp;

            for(int k = 0; k < k1; k++)
            {

                for(int l = 0; l < l1; l++)
                {
                    random = rand() % 20;
                    vec[i][j][k][l] = random;
                    //std::cout << vec[i][j][k][l] << " ";

                }
            }
        }
        std::cout << "\n";
    }


    c.setMatrix(row, col, k1, l1, vec);
    c.printMatrix();

    std::cout << "\n";
    return 0;
}
