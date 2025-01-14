#include <iostream>
using namespace std;

int MaxCustomers = 10;

void AddReservation(string Names[],int& Customers, const int& MaxCustomers){
    char AddCustomer;
    string NewName;   
    cout << "Masukkan nama pelanggan baru\n";
    cout << "> ";
    getline(cin, NewName);

    if(Customers < MaxCustomers){
        Names[Customers] = NewName;
        Customers++;
    }
    else{
        cout << "Meja telah penuh\n";
        return;
    }

    cout << "Ingin menambah reservasi lagi? (y/n)\n";
    cout << "> ";
    cin >> AddCustomer; 
    cin.ignore();

    if(AddCustomer == 'y'){
        AddReservation(Names, Customers, MaxCustomers);
    }
}

void ListReservation(string Names[],int Stack, int& Customers){
    if(Stack == Customers){
        return;
    }
    cout << "Meja " << Stack+1 << ", atas nama " << Names[Stack] << endl;
    ListReservation(Names,Stack+1,Customers);
}

bool FindReservation(string Names[], int Start, int End, const string& TargetedName) {
    if(Start > End){
        return false;
    }
    if(Names[Start] == TargetedName){
        return true;
    }
    return FindReservation(Names, Start + 1, End - 1, TargetedName); 
}

int main() {
    string Names[MaxCustomers] = {};
    int Customers = 0;

    char LoginAdmin = 'y';
        while(LoginAdmin == 'y'){
            int Input;
            system("cls");
            cout << "==== Dashboard Admin ====\n";
            cout << "1. Menambah Reservasi\n";
            cout << "2. Menampilkan Daftar Reservasi\n";
            cout << "3. Mencari Nama Reservasi\n";
            cout << "4. Keluar\n";
            cout << "> ";
            cin >> Input;
            cin.ignore();    
                
                if(Input == 1){
                    cout << endl;
                    AddReservation(Names, Customers, MaxCustomers);
                }

                else if(Input == 2){
                    cout << endl;
                    cout << "Daftar Reservasi\n\n";
                    ListReservation(Names, 0, Customers);
                    cout << "\nKlik Enter untuk melanjutkan";
                    cin.get();
                    cout << endl;
                }
                
                else if(Input == 3){
                    string TargetedName;

                    cout << "Masukkan nama yang ingin dicari: ";
                    getline(cin, TargetedName);

                    bool Found = FindReservation(Names, 0, 9, TargetedName); 

                    if (Found) {
                        cout << endl << TargetedName << " telah memesan meja\n\n";
                    } else {
                        cout << endl << TargetedName << " belum memesan meja\n\n";
                    }
                    cout << "Klik Enter untuk melanjutkan";
                    cin.get();
                }

                else if(Input == 4){
                    char Exit;
                    cout << "Apakah anda ingin keluar dari akses Admin (y/n)\n";
                    cout << "> ";
                    cin >> Exit;

                    if(Exit == 'y' || Exit == 'Y'){
                        LoginAdmin = 'n';
                    }
                
                
                    else{
                        LoginAdmin = 'y';
                    }
                }
            }
    return 0;
}
/* Fungsi Fibonacci Rekursif
int Fibonacci(int N){
    if(N == 0){ 
        return 0;
    }
    if(N == 1){ 
        return 1;
    }
    else{ 
        return Fibonacci(N-1) + Fibonacci(N-2); // disinilah proses fibonacci dilakukan
    }
}*/

/* Fungsi Counting Number Line Recursion
void counting_number(int n){
    if(n > 0){
        cout << n << " ";
        counting_number(n-1);
    }
}

int main(){
    int x;
    cin >> x;
    counting_number(x);
}*/

/* Fungsi IsEven dan IsOdd Indirect Recursion
bool isEven(int N);
bool isOdd(int N);

bool isEven(int N){
    if(N == 0){
        return true;
    }
    else{
        return isOdd(N-1);
    }
}

bool isOdd(int N){
    if(N == 0){
        return false;
    }
    else{
        return isEven(N-1);
    }
}*/

/* Fungsi Counting Number Non Tail Recursion
void counting_number(int n){
    if(n > 0){
        counting_number(n-1);
        cout << n << " ";
    }
}

int main(){
    int x;
    cin >> x;
    counting_number(x);
}*/

/* Program Tanpa Fungsi Rekursif
void AddReservation(string Names[],int& Customers, const int& MaxCustomers){
    char AddCustomer = 'y';
    while(AddCustomer == 'y'){
        string NewName;   
        cout << "Masukkan nama pelanggan baru\n";
        cout << "> ";
        getline(cin, NewName);

        if(Customers < MaxCustomers){
            Names[Customers] = NewName;
            Customers++;
        }
        else{
            cout << "Meja telah penuh\n";
            return;
        }

        cout << "Ingin menambah reservasi lagi? (y/n)\n";
        cout << "> ";
        cin >> AddCustomer; 
        cin.ignore();
    }
}

void ListReservation(string Names[],int& Customers){
    for(int i = 0; i < Customers; i++){
    cout << "Meja " << i+1 << ", atas nama " << Names[i] << endl;
    }
}

bool FindReservation(string Names[], int& Customers, const string& TargetedName) {
    for(int i = 0; i < Customers; i++){
    if(Names[i] == TargetedName){
        return true;
        }
    }
    return false;    
}

int main() {
    string Names[MaxCustomers] = {};
    int Customers = 0;

    char LoginAdmin = 'y';
        while(LoginAdmin == 'y'){
            int Input;
            system("cls");
            cout << "==== Dashboard Admin ====\n";
            cout << "1. Menambah Reservasi\n";
            cout << "2. Menampilkan Daftar Reservasi\n";
            cout << "3. Mencari Nama Reservasi\n";
            cout << "4. Keluar\n";
            cout << "> ";
            cin >> Input;
            cin.ignore();    
                
                if(Input == 1){
                    cout << endl;
                    AddReservation(Names, Customers, MaxCustomers);
                }

                else if(Input == 2){
                    cout << endl;
                    cout << "Daftar Reservasi\n\n";
                    ListReservation(Names, Customers);
                    cout << "\nKlik Enter untuk melanjutkan";
                    cin.get();
                    cout << endl;
                }
                
                else if(Input == 3){
                    string TargetedName;

                    cout << "Masukkan nama yang ingin dicari: ";
                    getline(cin, TargetedName);

                    bool Found = FindReservation(Names, Customers, TargetedName); 

                    if (Found) {
                        cout << endl << TargetedName << " telah memesan meja\n\n";
                    } else {
                        cout << endl << TargetedName << " belum memesan meja\n\n";
                    }
                    cout << "Klik Enter untuk melanjutkan";
                    cin.get();
                }

                else if(Input == 4){
                    char Exit;
                    cout << "Apakah anda ingin keluar dari akses Admin (y/n)\n";
                    cout << "> ";
                    cin >> Exit;

                    if(Exit == 'y' || Exit == 'Y'){
                        LoginAdmin = 'n';
                    }
                
                
                    else{
                        LoginAdmin = 'y';
                    }
                }
            }
    return 0;
}*/


