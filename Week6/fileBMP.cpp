#include <iostream>
#include <fstream>

int main(){
    std::fstream file;
    file.open("NIC.bmp", std::ios::binary
                                |std::ios::in
                                |std::ios::out);
    if (!file){
        std::cout<<"Error opening file\n";
        exit(1);
    }
    uint8_t magic[2];
    file.read(reinterpret_cast<char*>(magic), 2);
    if (magic[0]=='B' && magic[1]=='M'){
        std::cout<<"It is a BMP file...\n";
    }else{
        std::cout<<"It is not a BMP file...\n";
        exit(1);
    }
    file.seekg(30, std::ios::beg);
    uint32_t compress;
    file.read(reinterpret_cast<char*>(&compress), sizeof(compress));
    if (compress==0){
        std::cout<<"...with out compression...\n";
    }else{
        std::cout<<"...with compression...\n";
        exit(1);
    }

    //find the offset of pixel array
    file.seekg(10, std::ios::beg);
    uint32_t offset_of_pixel;
    file.read(reinterpret_cast<char*>(&offset_of_pixel), sizeof(offset_of_pixel));
    std::cout<<"The pixel array starts at byte "<<offset_of_pixel<<
                " = "<<std::hex<<offset_of_pixel<<" in hex\n";

    //find the width of pixel array
    file.seekg(18, std::ios::beg);
    uint32_t width;
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    std::cout<<"The width of pixel array is "<<std::dec<<width<<" pixels\n";

    uint8_t color[3]={202, 21, 219};
    file.seekp(offset_of_pixel, std::ios::beg);
    for (unsigned int i = 0; i < width; i++){
        file.write(reinterpret_cast<char*>(color), 3);
    }

    //Flip LSB of the last raw in pixel array (first raw in image)
    //number of bytes in raw = total number of bytes in pixel array(offset 34) 
    //                         / by number of raws(offset 22)
    long int bytes_in_raw;
    uint32_t total_bytes;
    uint32_t hight;
    file.seekg(22, std::ios::beg);
    file.read(reinterpret_cast<char*>(&hight), sizeof(hight));
    std::cout<<"The hight of pixel array is "<<width<<" \n";

    file.seekg(34, std::ios::beg);
    file.read(reinterpret_cast<char*>(&total_bytes), sizeof(total_bytes));
    std::cout<<"The total number of bytes in pixel array is "<<total_bytes<<" \n";

    bytes_in_raw=total_bytes/hight;
    std::cout<<"The total number of bytes in raw is "<<bytes_in_raw<<" \n";

    file.seekg(-1*bytes_in_raw, std::ios::end);//begining of last raw
    uint8_t byte;
    for (int i = 0; i <bytes_in_raw; i++){
        //read a byte
        file.read(reinterpret_cast<char*>(&byte), 1);
        //flip LSB
        byte = byte^1;
        //write the byte
        file.seekg(-1, std::ios::cur);
        file.write(reinterpret_cast<char*>(&byte), 1);
    }


    file.close();





    return 0;
}