#include"NhanVien.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

NhanVien::NhanVien(){};
NhanVien::NhanVien(string maNhanVien, string hoTen, string ngaySinh, string soDienThoai, string email)
  : maNhanVien(maNhanVien), hoTen(hoTen), ngaySinh(ngaySinh), soDienThoai(soDienThoai), email(email){};
     
void NhanVien::ThemNhanVien(){
    cout << "Nhap ma nhan vien: ";
    cin >> maNhanVien;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay thang nam sinh: ";
    cin >> ngaySinh;
    cout << "Nhap so dien thoai: ";
    cin >> soDienThoai;
    cout << "Nhap email: ";
    cin >> email ;
    cout << "Them nhan vien thanh cong!" << endl;
    NhanVien* nv = new NhanVien(maNhanVien, hoTen, ngaySinh, soDienThoai, email);
    danhSachNhanVien.push_back(*nv);
}
void NhanVien::XoaNhanVien(){
    string maNhanVien;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> maNhanVien;
    for(int i = 0; i < danhSachNhanVien.size(); i++){
        if(danhSachNhanVien[i].maNhanVien == maNhanVien){
            danhSachNhanVien.erase(danhSachNhanVien.begin() + i);
            cout << "Xoa thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}
void NhanVien::SuaNhanVien(){
    string maNhanVien;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> maNhanVien;
    for(int i = 0; i < danhSachNhanVien.size(); i++){
        if(danhSachNhanVien[i].maNhanVien == maNhanVien){
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, danhSachNhanVien[i].hoTen);
            cout << "Nhap ngay thang nam sinh: ";
            cin >> danhSachNhanVien[i].ngaySinh;
            cout << "Nhap so dien thoai: ";
            cin >> danhSachNhanVien[i].soDienThoai;
            cout << "Nhap email: ";
            cin >> danhSachNhanVien[i].email;
            cout << "Sua thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}
void NhanVien::TimKiemNhanVien(){
    string maNhanVien;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> maNhanVien;
    for(int i = 0; i < danhSachNhanVien.size(); i++){
        if(danhSachNhanVien[i].maNhanVien == maNhanVien){
            cout << "| STT |      ID      |        Ho va ten      |     Ngay sinh    |   So dien thoai   |            Email           |" << endl;
            HienThi(i);
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}
// đã fix hiển thị
void NhanVien::HienThi(const int& i) {
    cout <<"| " << i+1 ;
    int dem =0 ;
    while(1){
        if(dem<4-to_string(i+1).length()){
            cout << " ";
            dem++;
        }
        else break;
    }
    cout << "| " << danhSachNhanVien[i].maNhanVien;
    for(int j = 0; j < 13 - danhSachNhanVien[i].maNhanVien.length(); j++){
        cout << " ";
    }
    cout << "| " << danhSachNhanVien[i].hoTen;
    for(int j = 0; j < 22 - danhSachNhanVien[i].hoTen.length(); j++){
        cout << " ";
    }
    cout << "| " << danhSachNhanVien[i].ngaySinh;
    for(int j = 0; j < 17 - danhSachNhanVien[i].ngaySinh.length(); j++){
        cout << " ";
    }
    cout << "| " << danhSachNhanVien[i].soDienThoai;
    for(int j = 0; j < 18 - danhSachNhanVien[i].soDienThoai.length(); j++){
        cout << " ";
    }
    cout << "| " << danhSachNhanVien[i].email;
    for(int j = 0; j < 27 - danhSachNhanVien[i].email.length(); j++){
        cout << " ";
    }
    cout << "|" << endl;
}
void NhanVien::HienThiDanhSachNhanVien(){

     cout << "| STT |      ID      |        Ho va ten      |     Ngay sinh    |   So dien thoai   |            Email           |" << endl;
    for(int i = 0; i < danhSachNhanVien.size(); i++){
        HienThi(i);
    }
}
// đang lỗi cái không đọc được file.txt , ghi đè thì được nhưng không đọc được dữ liệu có sẵn
void NhanVien::LuuDSNhanVien(){
    ofstream file("data/nhanvien.txt");
    for(int i = 0; i < danhSachNhanVien.size(); i++){
        file << danhSachNhanVien[i].maNhanVien << ";" ;
        file << danhSachNhanVien[i].hoTen << ";" ;
        file << danhSachNhanVien[i].ngaySinh << ";" ;
        file << danhSachNhanVien[i].soDienThoai << ";" ;
        file << danhSachNhanVien[i].email << endl;
    }
    cout << "Luu file thanh cong!" << endl;
    file.close();
}
// không đọc được dữ liệu có sẵn trong file
void NhanVien::DocDSNhanVien(){
    ifstream file("data/nhanvien.txt");
     if (!file.is_open()) {
        cout << "Khong the mo file de doc!" << endl;
        return;
    }
    danhSachNhanVien.clear();
    while(getline(file, maNhanVien, ';')){
        getline(file, hoTen,';');
        getline(file, ngaySinh,';');
        getline(file, soDienThoai,';');
        getline(file, email,'\n');
        if(!maNhanVien.empty()){
            NhanVien nv(maNhanVien, hoTen, ngaySinh, soDienThoai, email);
        danhSachNhanVien.push_back(nv);
        }
    }
    cout << "Doc thanh cong!" << endl;
    file.close();
}