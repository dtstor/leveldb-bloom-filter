/*
 * bloomfilter.h
 *
 *  Created on: 2016Äê5ÔÂ12ÈÕ
 *      Author: gzl
 */

#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include<string>

class BloomFilterPolicy {
 private:
  size_t bits_per_key_;
  size_t k_;

 public:
  explicit BloomFilterPolicy(int bits_per_key);
  ~BloomFilterPolicy(){}
  void CreateFilter(const std::string* keys, int n, std::string* dst) const;
  bool KeyMayMatch(const std::string& key, const std::string& bloom_filter) const;

};


#endif /* BLOOMFILTER_H_ */
