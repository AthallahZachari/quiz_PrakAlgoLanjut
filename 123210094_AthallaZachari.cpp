#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ClassDataWarung
{
public:
    int kodeBarang;
    string namaBarang;
    int hargaBarang;
    int jumlahStok;
};
ClassDataWarung inventory[99];


int main(){
    int getNavigation();
    bool checkDuplicate(string name, int idx);
    void exportToFile(string &filename, int index);
    int checkIndex(string tempNamaBarang, int index);

    bool onLoop = true;
    string setLoop, inputCheckDuplicate;
    string filename, getFilename, tempNamaBarang;
    int navigation, tempIndex, tempJumlahStok;
    int index = 0;

    while (onLoop)
    {
        system("cls");
        cout << "===================\n";
        cout << "| ATHALLA ZACHARI |\n";
        cout << "| 123210094       |\n";
        cout << "===================\n\n";
        cout << "MAIN MENU\n1. Input Data Produk\n2. Show Data Produk\n3. Export File\n4. Exit\n";
        navigation = getNavigation();
        cin.ignore();

        switch (navigation)
        {
        case 1:
            system("cls");
            cout << "=====================\n";
            cout << "| DATA INPUT        |\n";
            cout << "| Index ke -  "<<index<<endl;
            cout << "| Input Data ke - " << index + 1 << " |\n";
            cout << "=====================\n\n";

            cout << "Nama Produk \t= ";
            getline(cin, tempNamaBarang);

            if(checkDuplicate(tempNamaBarang, index)){ 
                tempIndex = checkIndex(tempNamaBarang, index);
                cout << "Jumlah Produk \t= ";
                cin>>tempJumlahStok;
                cin.ignore();
                inventory[tempIndex-1].jumlahStok = inventory[tempIndex-1].jumlahStok + tempJumlahStok;
            }
            else{
                inventory[index].namaBarang = tempNamaBarang;
                cout << "Jumlah Produk \t= ";
                cin >> inventory[index].jumlahStok;
                cout<<"Kode Barang \t= ";
                cin>>inventory[index].kodeBarang;
                cout<<"Harga Barang \t= ";
                cin>>inventory[index].hargaBarang;
                cin.ignore();
                index++;
            }

            break;

        case 2:
            system("cls");
            cout<<"SHOW DATA\n";
            cout << "Jumlah data masuk - "<<index<<"\n\n";
            for(int i=0; i<index; i++){
                cout<<"Nama barang \t= "<<inventory[i].namaBarang<<endl;
                cout<<"Kode barang \t= "<<inventory[i].kodeBarang<<endl;
                cout<<"Harga barang \t= "<<inventory[i].hargaBarang<<endl;
                cout<<"Stok barang \t= "<<inventory[i].jumlahStok<<"\n\n";
            }
            break;

        case 3:
        {
            system("cls");
            cout << "=====================\n";
            cout << "| EXPORT DATA       |\n";
            cout << "=====================\n\n";
            cout << "Nama file : ";
            getline(cin, filename);
            exportToFile(filename, index);
            break;
        }
        case 4:
            system("cls");
            cout<<"Exiting...\n";
            return 0;
            break;

        default:
            break;
        }
        cout << "Kembali ke menu utama? (Y/N)";
        getline(cin, setLoop);
        setLoop == "Y" || setLoop == "y" ? onLoop = true : onLoop = false;
    }

    return 0;
}

bool checkDuplicate(string name, int idx){
    for (int i = 0; i < idx; i++){
        if (name == inventory[i].namaBarang){
            return true; //jika ada
        }
    }
    return false; //tidak ada
}

int checkIndex(string name, int idx){
    for(int i=0; i<idx; i++){
        if(name == inventory[i].namaBarang){
            return i+=1; //kalo ada
        }
    }
    return idx; //kalo ga ada
}

int getNavigation()
{
    int selectedNav;

    cout << "Pilih : ";
    cin >> selectedNav;

    if (selectedNav < 1 || selectedNav > 4)
    {
        cout << "Input salah, silahkan masukkan input yang benar!!\n";
        return getNavigation();
    }
    return selectedNav;
}

void exportToFile(string &filename, int index){
    ofstream outfile(filename);
    if (!outfile.is_open()){
        cout << "Error opening file : " << filename << endl;
        return;
    }
    cout<<"jumlah index - "<<index;
    for (int i = 0; i < index; i++){
        if(inventory[i].kodeBarang != 0){
            outfile<<
            "Barang ke - "<<i<<"\n"<<
            "Nama barang \t= "<<inventory[i].namaBarang<<"\n"<<
            "Kode barang \t= "<<inventory[i].kodeBarang<<"\n"<<
            "Harga barang \t= "<<inventory[i].hargaBarang<<"\n"<<
            "Jumlah barang \t= "<<inventory[i].jumlahStok<<"\n\n";
            //outfile<<inventory[i].kodeBarang<<" "<<inventory[i].jumlahStok<<" "<<inventory[i].namaBarang<<" "<<inventory[i].hargaBarang<<endl;
        }
    }
    outfile.close();
};