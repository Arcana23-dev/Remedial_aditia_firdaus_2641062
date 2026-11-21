#include <iostream>
#include <iomanip>

int main() {
    char kode, member;
    int berat;
    int tarif = 0;
    const char* layanan = "";

    double subtotal, diskon, total;

if (!(std::cin >> kode >> berat >> member)){
    std::cout << "Input tidak valid." << std::endl;
    return 0;
}

if (berat < 1 || berat > 20 ||
    (member != 'Y' && member != 'T')){
    std::cout << "Input tidak valid" << std::endl;
    return 0;
}

if (kode == 'C') {
    tarif = 8000;
    layanan = "Cuci";
}
else if (kode == 'S') {
    tarif = 12000;
    layanan = "Cuci Setrika";
}
else if (kode == 'E') {
    tarif = 18000;
    layanan = "Express";
}
else {
    std::cout << "Kode layanan tidak valid" << std::endl;
    return 0;
}

subtotal = tarif*berat;
diskon = 0;

if (berat <= 10 && member == 'Y') {
    diskon = subtotal * 0.10;
}
else if (berat > 10 && member == 'Y') {
    diskon = subtotal * 0.15;
}
else if (berat > 10 && member == 'T') {
    diskon = subtotal * 0.05;
}

total = subtotal - diskon;

std::cout << std::fixed << std::setprecision(2);

std::cout << "Layanan       : " << layanan << std::endl;
std::cout << "Berat         : " << berat << " kg" << std::endl;
std::cout << "Subtotal      : " << subtotal << std::endl;
std::cout << "Diskon        : " << diskon << std::endl;
std::cout << "Total         : " << total << std::endl;

return 0;
}