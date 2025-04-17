#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import pickle # dump
from collections import defaultdict

# 2gram 언어 모델 학습
# unigram 빈도와 bigram 빈도를 리턴
# 문장의 앞뒤에 시작(<s>)과 끝(</s>)을 나타내는 가상의 단어를 포함해야 함
# 단어 토큰은 공백을 기준으로 분리
def learn_bigram_language_model(input_file):
    # 단어 빈도를 저장할 dictionary
    unigram_counts = defaultdict(int)
    bigram_counts = {} # dictionary of dictionary
    with open(input_file, 'r') as file:
        for line in file:
            data = '<s> ' + line.strip() + ' </s>'
            data = list(data.split())
            for i in range(len(data)):
                if data[i] not in unigram_counts:
                    unigram_counts[data[i]] = 1
                else:
                    unigram_counts[data[i]] += 1
                if data[i] != '</s>':
                    if data[i] not in bigram_counts:
                        bigram_counts[data[i]] = defaultdict(int)
                        bigram_counts[data[i]][data[i+1]] = 1
                    else:
                        if data[i+1] not in bigram_counts[data[i]]:
                            bigram_counts[data[i]][data[i+1]] = 1
                        else:
                            bigram_counts[data[i]][data[i+1]] += 1
    return unigram_counts, bigram_counts

################################################################################
def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} input_file output_file(pickle)")
        sys.exit(1)
        
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    
    # 모델 학습
    unigram_counts, bigram_counts = learn_bigram_language_model(input_file)
    
    # 모델 저장
    model = {
        'unigram_counts': unigram_counts,
        'bigram_counts': bigram_counts
    }
    
    with open(output_file, 'wb') as f:
        pickle.dump(model, f)

################################################################################
if __name__ == "__main__":
    main() 
