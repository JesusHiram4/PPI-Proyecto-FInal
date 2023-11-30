#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <locale>
#include <fstream><

using namespace std;

class Carro{
private:
    string marca,modelo,color,tipo_de_motor;
    int velocidad_maxima,year,kilometraje,id;
	float HorsePower;
	vector<string> artilugios_interior;

public:
	Carro(int id, string marca, string modelo, string color, string tipo_de_motor, int velocidad_maxima, int year, int kilometraje, float HorsePower, vector<string> artilugios_interior){
    this->id = id;
	this->marca = marca;
    this->modelo = modelo;
	this->color = color;
	this->tipo_de_motor = tipo_de_motor;
	this->velocidad_maxima = velocidad_maxima;
	this->year = year;
	this->kilometraje = kilometraje;
	this->HorsePower = HorsePower;
	this->artilugios_interior = artilugios_interior;
	}

    void mostrarDatos(){
        cout << "\nLa ID del carro es " << this->id << endl;
        cout << "La marca del carro es " << this->marca << endl;
        cout << "El modelo del carro es " << this->modelo << endl;
        cout << "El color del carro es " << this->color << endl;
        cout << "El tipo de motor del carro es " << this->tipo_de_motor << endl;
        cout << "La velocidad maxima del carro es " << this->velocidad_maxima << endl;
        cout << "El año del carro es " << this->year << endl;
        cout << "El kilometraje del carro es " << this->kilometraje << endl;
        cout << "La potencia del carro es " << this->HorsePower << endl;
        cout << "Los Artilugios del interior del carro son: \n";
        for(int i=0;i<this->artilugios_interior.size();i++){
            cout << i+1 << ".-" << this->artilugios_interior[i] << endl;
        }
        cout << endl;
    }

    int getId(){
        return this->id;
    }

    string getMarca(){
        return this->marca;
    }

    void setMarca(string marca){
        this->marca = marca;
    }

    string getModelo(){
        return this->modelo;
    }

    void setModelo(string modelo){
        this->modelo = modelo;
    }

    string getColor(){
        return this->color;
    }

    void setColor(string color){
        this->color = color;
    }

    string getTipodemotor(){
        return this->tipo_de_motor;
    }

    void setTipodemotor(string tipo_de_motor){
        this->tipo_de_motor = tipo_de_motor;
    }

    int getVelocidadMax(){
        return this->velocidad_maxima;
    }

    void setVelocidadMax(int velocidad_maxima){
        this->velocidad_maxima = velocidad_maxima;
    }

    int getYear(){
        return this->year;
    }

    void setYear(int year){
        this->year = year;
    }

    int getKilometraje(){
        return this->kilometraje;
    }

    void setKilometraje(int kilometraje){
        this->kilometraje = kilometraje;
    }

    float getPotencia(){
        return this->HorsePower;
    }

    void setPotencia(int HorsePower){
        this->HorsePower = HorsePower;
    }

    string getArtilugiosInterior(int n){
        return this->artilugios_interior[n+1];
    }

    void setArtilugiosInterior(string artilugio_interior,int id,int n){
        if(n == 1){
            this->artilugios_interior.push_back(artilugio_interior);
        }else if(n == 2){
            this->artilugios_interior.erase(this->artilugios_interior.begin() + id);
        }else{
            this->artilugios_interior[id-1] = artilugio_interior;
        }
    }


};


int identificador(vector<Carro>* objeto,int id){
    int p = -1;
    for(int i=0;i<objeto->size();i++){
        if(id == (*objeto)[i].getId()){
            p = i;
        }
    }
    return p;
}

void create(vector<Carro>* objeto, ofstream& Archivo){
    string marca;
    string modelo;
    string color;
    string tipo_de_motor;
    int velocidad_maxima;
    int year;
    int kilometraje;
    int cantidad;
	float HorsePower;
	vector<string> artilugios_interior;
	string artilugio_interior;

	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(static_cast<unsigned int>(seed));
    uniform_int_distribution<int> distribution(100000, 999999);

    int ID = distribution(generator);
    cin.ignore();
    cout << "Ingrese la marca del nuevo carro: ";
    getline(cin,marca);
    cout << "Ingrese el modelo del nuevo carro: ";
    getline(cin,modelo);
    cout << "Ingrese el color del nuevo carro: ";
    getline(cin,color);
    cout << "Ingrese el tipo de motor del nuevo carro: ";
    getline(cin,tipo_de_motor);
    do{
        cout << "Ingrese la velocidad maxima del nuevo carro (en km/h): ";
        if (cin >> velocidad_maxima) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            velocidad_maxima = -1;
        }
    }while(velocidad_maxima == -1);
    do{
        cout << "Ingrese el año del nuevo carro: ";
        if (cin >> year) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            year = -1;
        }
    }while(year == -1);
    do{
        cout << "Ingrese el kilometraje del nuevo carro: ";
        if (cin >> kilometraje) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            kilometraje = -1;
        }
    }while(kilometraje == -1);
    do{
        cout << "Ingrese la potencia(en HP) nueva del carro: ";
        if (cin >> HorsePower) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            HorsePower = -1;
        }
    }while(HorsePower == -1);
    do{
        cout << "Ingrese la cantidad de artilugios interiores que tiene el carro: ";
        if (cin >> cantidad) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cantidad = -1;
        }
    }while(cantidad == -1);
    cin.ignore();
    for(int i=0;i<cantidad;i++){
        cout << i+1 << ".-Ingrese el artilugio interior: ";
        getline(cin,artilugio_interior);
        artilugios_interior.push_back(artilugio_interior);
    }
    cout << endl;
    cout << "El ID del carro es " << ID << endl << endl;

Carro car(ID, marca, modelo, color, tipo_de_motor, velocidad_maxima, year, kilometraje, HorsePower, artilugios_interior);
objeto->push_back(car);
Archivo <<"ID: "<< ID<<"\n";
Archivo << "Marca: " << marca << "\n";
Archivo << "Modelo: " << modelo << "\n";
Archivo << "Tipo de Motor: " << tipo_de_motor << "\n";
Archivo << "Velocidad Maxima: " << velocidad_maxima << "\n";
Archivo << "Año del carro: " << year << "\n";
Archivo << "Kilometraje: " << kilometraje << "\n";
Archivo << "HorsePower: " << HorsePower << "\n";
Archivo << "Artilogios en el interior:\n";
for (const string& artilugio_interior : artilugios_interior) {
    Archivo << artilugio_interior << "\n";
}
Archivo << "\n";

}

void read(vector<Carro>* objeto, ifstream& Ar){
    char c;
    string cadena;
    int id;
    string modelo;
    cout << "Ingrese i o m para acceder a los datos del carro por id o modelo respectivamente: ";
    cin >> cadena;
    c = cadena[0];
    if(c == 'i'){
        do{
            cout << "Ingrese el id del carro al que quiere acceder: ";
            if (cin >> id) {
//                while(getline(&carros, Ar))
//                (*objeto)[identificador(objeto,id)].mostrarDatos();
            } else {
                cout << "Error: Ingrese un numero valido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                id = -1;
            }
        }while(id == -1);
        if(identificador(objeto,id) != -1){
        (*objeto)[identificador(objeto,id)].mostrarDatos();
        }else{
            cout << "El carro no existe" << endl;
        }
    }else if(c == 'm'){
        cin.ignore();
        cout << "Ingrese el modelo del carro al que quiere acceder: ";
        getline(cin,modelo);
        for(int i=0;i<objeto->size();i++){
            if(modelo == (*objeto)[i].getModelo()){
                (*objeto)[i].mostrarDatos();
                break;
            }else if(i == objeto->size()-1){
                cout << "\nEl modelo que ingreso no existe\n\n";
            }
        }
    }
}

void update(vector<Carro>* objeto){
    int id;
    int propiedad;

    do{
        cout << "Ingrese el ID del carro que quiere modificar: ";
        if (cin >> id) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            id = -1;
        }
    }while(id == -1);

    if(identificador(objeto,id) != -1){

        do{
            cout << "1.Marca 2.Modelo 3.Color 4.tipo de motor 5.velocidad maxima 6.año 7.kilometraje 8.potencia 9.artilugios interior\nIngrese la propiedad que desea modificar: ";
            if (cin >> propiedad) {
            } else {
                cout << "Error: Ingrese un numero valido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                propiedad = -1;
            }
        }while(propiedad == -1);

        cin.ignore();
        switch(propiedad){
            case 1:
                {
                string marca;
                cout << "Ingrese la nueva marca: ";
                getline(cin,marca);
                (*objeto)[identificador(objeto,id)].setMarca(marca);
                }
                break;
            case 2:
                {
                string modelo;
                cout << "Ingrese el nuevo modelo: ";
                getline(cin,modelo);
                (*objeto)[identificador(objeto,id)].setModelo(modelo);
                }
                break;
            case 3:
                {
                string color;
                cout << "Ingrese el nuevo color: ";
                getline(cin,color);
                (*objeto)[identificador(objeto,id)].setColor(color);
                }
                break;
            case 4:
                {
                string tipo_de_motor;
                cout << "Ingrese el nuevo tipo de motor: ";
                getline(cin,tipo_de_motor);
                (*objeto)[identificador(objeto,id)].setTipodemotor(tipo_de_motor);
                }
                break;
            case 5:
                {
                int velocidad_maxima;
                do{
                    cout << "Ingrese la velocidad maxima del nuevo carro (en km/h): ";
                    if (cin >> velocidad_maxima) {
                    } else {
                        cout << "Error: Ingrese un numero valido." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        velocidad_maxima = -1;
                    }
                }while(velocidad_maxima == -1);
                (*objeto)[identificador(objeto,id)].setVelocidadMax(velocidad_maxima);
                }
                break;
            case 6:
                {
                int year;
                do{
                    cout << "Ingrese el año del nuevo carro: ";
                    if (cin >> year) {
                    } else {
                        cout << "Error: Ingrese un numero valido." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        year = -1;
                    }
                }while(year == -1);
                (*objeto)[identificador(objeto,id)].setYear(year);
                }
                break;
            case 7:
                {
                int kilometraje;
                do{
                    cout << "Ingrese el kilometraje del nuevo carro: ";
                    if (cin >> kilometraje) {
                    } else {
                        cout << "Error: Ingrese un numero valido." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        kilometraje = -1;
                    }
                }while(kilometraje == -1);
                (*objeto)[identificador(objeto,id)].setKilometraje(kilometraje);
                }
                break;
            case 8:
                {
                float HorsePower;
                do{
                    cout << "Ingrese la potencia (en HP) del nuevo carro: ";
                    if (cin >> HorsePower) {
                    } else {
                        cout << "Error: Ingrese un numero valido." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        HorsePower = -1;
                    }
                }while(HorsePower == -1);
                (*objeto)[identificador(objeto,id)].setPotencia(HorsePower);
                }
                break;
            case 9:
                {
                int n = -1;
                string artilugio_interior;
                do{
                    cout << "1.-Agregar un artilugio, 2.-Eliminar un artilugio, 3-Modificar un artilugio: ";
                    if (cin >> n) {
                    } else {
                        cout << "Error: Ingrese un numero valido." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        n = -1;
                    }
                }while(n == -1);
                cin.ignore();
                if(n == 1){
                    cout << "Ingrese el nombre del artilugio que desea agregar: ";
                    getline(cin,artilugio_interior);
                    (*objeto)[identificador(objeto,id)].setArtilugiosInterior(artilugio_interior,0,1);
                }else if(n == 2){
                    do{
                        cout << "Ingrese el numero de artilugio de interior que desea eliminar: ";
                        if (cin >> n) {
                        } else {
                            cout << "Error: Ingrese un numero valido." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            n = -1;
                        }
                    }while(n == -1);
                    (*objeto)[identificador(objeto,id)].setArtilugiosInterior(" ",n,2);
                }else if(n == 3){
                    do{
                        cout << "Ingrese el numero de artilugio de interior que desea modificar: ";
                        if (cin >> n) {
                        } else {
                            cout << "Error: Ingrese un numero valido." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            n = -1;
                        }
                    }while(n == -1);
                    cin.ignore();
                    cout << "Ingrese el nombre nuevo del artilugio de interior: ";
                    getline(cin,artilugio_interior);
                    (*objeto)[identificador(objeto,id)].setArtilugiosInterior(artilugio_interior,n,3);
                }
                }
                break;
            default:
                cout << "No existe esa propiedad";
        }
    }else{
        cout << "El ID del carro que desea actualizar no existe" << endl;
    }


    cout << endl;
}

void del(vector<Carro>* objeto){
    int id;

    do{
        cout << "Ingrese el id del objeto que desea eliminar: ";
        if (cin >> id) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            id = -1;
        }
    }while(id == -1);

    if(identificador(objeto,id) != -1){
        (*objeto).erase((*objeto).begin() + identificador(objeto,id));
    }else{
        cout << "El objeto no existe" << endl;
    }
    cout << endl;
}

void potenciaMayor(vector<Carro>* objeto){
    int c,n,id,mayorID,mayorPotencia;
    vector<Carro> vec;

    do{
        cout << "Para conocer el auto con mayor potencia ingrese\n1.-Todos los autos, 2.-Autos seleccionados: ";
        if (cin >> c) {
        } else {
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(c == 2 && (*objeto).size() < 3){
            cout << "\nEl minimo de autos para seleccionar debe de ser de 3" << endl;
            c = 0;
        }
    }while(c != 1 && c != 2);
    mayorID = (*objeto)[0].getId();
    mayorPotencia = (*objeto)[0].getPotencia();
    if(c == 1){
        mayorID = (*objeto)[0].getId();
        for(int i=0;i<(*objeto).size()-1;i++){
            if(mayorPotencia < (*objeto)[i+1].getPotencia()){
                mayorID = (*objeto)[i+1].getId();
                mayorPotencia = (*objeto)[i+1].getPotencia();
            }
        }
    }else{
        do{
            cout << "Cantidad de autos que desea comparar para sacar la potencia mayor (max " << (*objeto).size()-1 << "): ";
            if (cin >> n) {
            } else {
                cout << "Error: Ingrese un numero valido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(n <= 1 || n >= (*objeto).size());

        for(int i=0;i<n;i++){
            do{
                if(id == -1){
                    cout << "El ID ingresado no existe\n";
                }
                cout << i+1 << ".-Ingrese el ID: ";
                if (cin >> id) {
                } else {
                    cout << "Error: Ingrese un numero valido." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(identificador(objeto,id) == -1);
            vec.push_back((*objeto)[identificador(objeto,id)]);
        }
        mayorID = vec[0].getId();
        mayorPotencia = vec[0].getPotencia();
        for(int i=0;i<vec.size()-1;i++){
            if(mayorPotencia < vec[i+1].getPotencia()){
                mayorID = vec[i+1].getId();
                mayorPotencia = vec[i+1].getPotencia();
            }
        }
    }
    cout << "\nEl auto con mayor potencia es el modelo " << (*objeto)[identificador(objeto,mayorID)].getModelo() << endl;
    cout << "Con una potencia de " << (*objeto)[identificador(objeto,mayorID)].getPotencia() << endl;
    cout << "Con ID " << (*objeto)[identificador(objeto,mayorID)].getId() << endl;

    cout << endl;
}

int main() {
    setlocale(LC_ALL,"");
    vector<Carro> carros;
    string cadena;
    char c;
    ofstream archivo("carros.txt",ios::out | ios::app);
    ifstream Ar("carros.txt");
    do{
        switch(carros.size()){
            case 0:
                cout << "Operaciones con objetos\nc para crear o s para salir: ";
                cin >> cadena;
                c = cadena[0];
                cout << endl;
                if(c == 'c'){
                    if(archivo.is_open()){
                        vector<Carro>carros;
                        create(&carros,archivo);
                    }
                    else{
                     cout<<"no se puede abrir el archivo"<<endl;
                    }
                }else{
                    c = 's';
                }
            default:
                if(c == 's'){
                    break;
                }
                cout << "Operaciones con objetos\nc para crear, r para leer, u para actualizar, d para eliminar, s para salir o h para conocer el auto con mayor HP: ";
                cin >> cadena;
                c = cadena[0];
                cout << endl;
                switch(c){
                    case 'c':
                        create(&carros,archivo);
                        break;
                    case 'r':
                        vector<Carro>carros;
                        if (Ar.is_open()){
                        string linea;
                        while(getline(Ar,linea))
                          read(&carros,Ar);
                        Ar.close();
                        }else {
                        cout<<"no se pudo abrir el archivo"<<endl;
                        }
                        break;
                    case 'u':
                        update(&carros);
                        break;
                    case 'd':
                        del(&carros);
                        break;
                    case 'h':
                        if(carros.size() < 2){
                            cout << "Debe de haber por lo menos 2 autos para comparar\n\n";
                        }else{
                            potenciaMayor(&carros);
                        }
                        break;
                    default:
                        c = 's';
                }
        }
    }while(c != 's');

    return 0;
}

