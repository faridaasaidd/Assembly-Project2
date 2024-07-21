#include <iostream>
#include  <iomanip>

using namespace std;

#define		DBG				1
#define		DRAM_SIZE		(64*1024*1024)
#define		CACHE_SIZE		(64*1024)

enum cacheResType {MISS=0, HIT=1};

/* The following implements a random number generator */
unsigned int m_w = 0xABABAB55;    /* must not be zero, nor 0x464fffff */
unsigned int m_z = 0x05080902;    /* must not be zero, nor 0x9068ffff */
unsigned int rand_()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  /* 32-bit result */
}

unsigned int memGen1()
{
    static unsigned int addr=0;
    return (addr++)%(DRAM_SIZE);
}

unsigned int memGen2()
{
    static unsigned int addr=0;
    return  rand_()%(24*1024);
}

unsigned int memGen3()
{
    return rand_()%(DRAM_SIZE);
}

unsigned int memGen4()
{
    static unsigned int addr=0;
    return (addr++)%(4*1024);
}

unsigned int memGen5()
{
    static unsigned int addr=0;
    return (addr++)%(1024*64);
}

unsigned int memGen6()
{
    static unsigned int addr=0;
    return (addr+=32)%(64*4*1024);
}


// Direct Mapped Cache Simulator
cacheResType cacheSimDM(unsigned int addr)
{
    unsigned int numLines = CACHE_SIZE / lineSize;
        unsigned int index = (addr / lineSize) % numLines;
        unsigned int tag = addr / (lineSize * numLines);

        if (directMappedCache[index].valid && directMappedCache[index].tag == tag) {
            return HIT;
        } else {
            directMappedCache[index].valid = true;
            directMappedCache[index].tag = tag;
            return MISS;
}

// Fully Associative Cache Simulator
cacheResType cacheSimFA(unsigned int addr)
{
    unsigned int tag = addr / lineSize;
    for (auto &line : fullyAssocCache) {
        if (line.valid && line.tag == tag) {
            return HIT;
        }
    }

    int replaceIndex = rand_() % fullyAssocCache.size();
    fullyAssocCache[replaceIndex].valid = true;
    fullyAssocCache[replaceIndex].tag = tag;
    return MISS;
}
char *msg[2] = {"Miss","Hit"};

#define		NO_OF_Iterations	100		// CHange to 1,000,000
        void runSimulation(unsigned int (*memGen)(), vector<unsigned int>& testAddresses, unsigned int lineSize, cacheResType (*cacheSim)(vector<CacheLine>&, unsigned int, unsigned int), vector<CacheLine>& cache, bool useMemGen)
    {
        double hitRatio;
        // Initialize cache
        fill(cache.begin(), cache.end(), CacheLine{false, 0});

        unsigned int hit = 0;
        unsigned int addr;
        cacheResType r;

        if (useMemGen) {
            for (int inst = 0; inst < 1000000; inst++) {
                addr = memGen();
                r = cacheSim(cache, addr, lineSize);
                if (r == HIT) hit++;
            }
            hitRatio = 100.0 * hit / 1000000;
        } else {
            for (unsigned int addr : testAddresses) {
                r = cacheSim(cache, addr, lineSize);
                if (r == HIT) hit++;
#if DBG
                cout << "Address: 0x" << setfill('0') << setw(8) << hex << addr
                     << " - " << msg[r] << endl;
#endif
            }
            hitRatio = 100.0 * hit / 8;

        }
        cout << "Hit ratio = " << hitRatio << "%" << endl;
    }


}

            int main()
{
     vector<unsigned int> testAddresses = {
            0x00000000, 0x00000020, 0x00000040, 0x00000060, 0x00000080,
            0x000000A0, 0x000000C0, 0x000000E0, 0x00000100, 0x00000120,
            0x00000140, 0x00000160, 0x00000180, 0x000001A0, 0x000001C0,
            0x000001E0, 0x00000200, 0x00000220, 0x00000240, 0x00000260,
            0x00000280, 0x000002A0, 0x000002C0, 0x000002E0, 0x00000300,
            0x00000320, 0x00000340, 0x00000360, 0x00000380, 0x000003A0
    };
    unsigned int hit = 0;
    cacheResType r;

    unsigned int addr;
    cout << "Direct Mapped Cache Simulator\n";

    for(int inst=0;inst<NO_OF_Iterations;inst++)
    {
        addr = memGen2();
        r = cacheSimDM(addr);
        if(r == HIT) hit++;
        cout <<"0x" << setfill('0') << setw(8) << hex << addr <<" ("<< msg[r] <<")\n";
    }
    cout << "Hit ratio = " << (100*hit/NO_OF_Iterations)<< endl;
}
