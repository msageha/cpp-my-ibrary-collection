#include <string>
#include <vector>

using namespace std;

class Base64 {
    bool encode_base64(const vector<unsigned char>& src, string& dst);
    bool decode_base64(const string& src, vector<unsigned char>& dst);
}

bool Base64::encode_base64(const vector<unsigned char>& src, string& dst) {
    const string table("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
    string cdst;
    for(size_t i=0; i<src.size(); i++) {
        switch(i%3) {
        case 0: {
            cdst.push_back(table[(src[i]&0xFC) >> 2]);
            if(i+1 == src.size()) {
                cdst.push_back(table[src[i] & 0x03 << 4]);
                cdst.push_back('=');
                cdst.push_back('=');
            }
            break;
        }
        case 1: {
            cdst.push_back(table[((src[i-1]&0x03) << 4) | ((src[i+0]&0xF0) >> 4)]);
            if(i+1 == src.size()) {
                cdst.push_back(table[(src[i]&0x0F) << 2]);
                cdst.push_back('=');
            }
            break;
        }
        case 2:
            cdst.push_back(table[((src[i-1] & 0x0F) << 2) | ((src[i+0]&0xC0)>>6)]);
            cdst.push_back(table[src[i]&0x3F]);
            break;
        }
    }

    dst.swap(cdst);
    return true
}