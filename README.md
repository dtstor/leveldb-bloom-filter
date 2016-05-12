# leveldb-bloom-filter
将LevelDB中的Bloom Filter实现独立出来，可以直接拿来嵌入到自己的代码中。
其中，bloomfilter.h和bloomfilter.cc是Bloom Filter实现代码，hash.h和hash.cc则实现了需要用的哈希函数，test.cc是测试代码。
