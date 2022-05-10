#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "SuperBlock.h"
#include "DiskDriver.h"
#include "Inode.h"

// The Disk Layout
static const unsigned int BLOCK_SIZE = 512;

static const unsigned int SUPER_BLOCK_INDEX = 0;
static const unsigned int SUPER_BLOCK_SIZE = 512;

static const unsigned int INODE_NUM = 256;
static const unsigned int INODE_SIZE = 64;

static const unsigned int BITMAP_START_INDEX = SUPER_BLOCK_INDEX + (SUPER_BLOCK_SIZE - 1) / BLOCK_SIZE + 1;
static const unsigned int BITMAP_SIZE = sizeof(int) * INODE_NUM;

static const unsigned int INODE_START_INDEX = BITMAP_START_INDEX + (BITMAP_SIZE - 1) / BLOCK_SIZE + 1;

static const unsigned int DATA_BLOCK_START_INDEX = INODE_START_INDEX + (INODE_NUM * INODE_SIZE - 1) / BLOCK_SIZE + 1;
static const unsigned int DATA_BLOCK_NUM = 2 * 1024 * 128;

static const unsigned int TOTAL_BLOCK_NUM = (DATA_BLOCK_NUM + DATA_BLOCK_START_INDEX); // The unit is MB
static const unsigned int DISK_SIZE = (TOTAL_BLOCK_NUM * BLOCK_SIZE) / (1024 * 1024);

class FileSystem
{
private:
    SuperBlock super_block;

    void Load_SuperBlock();
    void Store_SuperBlock();

    void Init_SuperBlock();
    void Init_All_Free_Blocks();
    void Init_BitMap();

    void Free_Inode(unsigned int inode_num);
    unsigned int Allocate_Inode();

public:
    void Format_Disk();
    // Return the block_num
    unsigned int Allocate_Block();
    void Free_Block(unsigned int block_num);
};

#endif