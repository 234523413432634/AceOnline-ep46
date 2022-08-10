#ifndef GAME_SHIELD_LIB_METAFILE_H
#define GAME_SHIELD_LIB_METAFILE_H

#pragma warning(disable : 4786)		// 2014-09-04 by ymjoo 컴파일 경고 제거 작업

#include "utility.h"
#include <set>

#define max_one_line_len 1100

struct file_descriptor
{
    file_descriptor(const std::string& = "");
    bool operator< (const file_descriptor& fd) const;
    bool pars_line(const char* buff, uint32 len);

    std::string m_path;
    std::string m_crc;
    uint32 m_size;
};

class metafile
{
public:
    metafile();
    bool load(const std::string& fname);

    std::string m_crcPath;
    std::set<file_descriptor> m_files;
    uint64 m_totalSize;
};

#endif //GAME_SHIELD_LIB_METAFILE_H

