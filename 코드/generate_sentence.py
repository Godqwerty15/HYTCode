#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import pickle # load
import random # choice, choices
import sys
import math # log

################################################################################
# 빈도를 가중치로 적용하여 다음 단어 선택 (random.choices 사용)
# 현재 단어가 모델에 없는 경우, 유니그램에서 랜덤하게 단어 선택
def get_next_word(model, current_word):
    if current_word not in model['bigram_counts']:
        word = random.choice(list(model['bigram_counts'].keys()))
    else:
        word_candidates  = list(model['bigram_counts'][current_word].keys())
        frequency = list(model['bigram_counts'][current_word].values())
        word = random.choices(word_candidates, weights = frequency, k = 1)[0]
    return word
################################################################################
# 문장의 로그 확률 계산 (로그 취한 개별 확률들의 합)
# 모델에 없는 단어 또는 단어 바이그램이 있으면 -100을 더함
def get_probability(model, sentence):
    # 로그 확률 초기화
    log_prob = 0.0
    sentence = '<s> ' + sentence + ' </s>'
    sentence = list(sentence.split())
    for i in range(len(sentence) - 1):
        if sentence[i] not in model['bigram_counts']:
            log_prob -= 100.0
        else:
            prob = model['bigram_counts'][sentence[i]][sentence[i+1]] / sum(model['bigram_counts'][sentence[i]].values())
            if prob == 0:
                log_prob -= 100.0
            else:
                log_prob += math.log(prob)
    return log_prob

################################################################################
# 랜덤 문장 생성
# start_with : 생성할 문장의 시작 단어(들). 없으면 '<s>'로 초기화
def generate_sentence(model, start_with):
    start_with.strip()
    if start_with == '\n':
        start_with = '<s>'
    sentence = list(start_with.split())
    temp = sentence[-1]
    while temp != '</s>':
        temp = get_next_word(model, temp)
        sentence.append(temp)
    if sentence[0] == '<s>':
        sentence = sentence[1:]
    sentence = sentence[:-1]
    return ' '.join(sentence)

################################################################################
def load_model(model_file):
    with open(model_file, 'rb') as f:
        return pickle.load(f)

################################################################################
def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} model_file")
        sys.exit(1)
    
    model_file = sys.argv[1]
    model = load_model(model_file)
    
    print("2-gram 언어 모델 문장 생성기")
    
    while True:
        cmd = input("\n엔터 또는 문장 시작 단어(들) (q=종료): ")
        
        if cmd.lower() == 'q':
            print("프로그램을 종료합니다.")
            break
        else:
            print("\n<<<< 생성된 문장 >>>>")
            
            for i in range(10):
                sentence = generate_sentence(model, cmd)
                log_prob = get_probability(model, sentence)
                print(f"문장{i+1} : {sentence} (로그 확률: {log_prob:.4f})")

################################################################################
if __name__ == "__main__":
    main() 
