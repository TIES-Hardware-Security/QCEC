#pragma once

#include "ApplicationScheme.hpp"
#include <set>
#include <iostream>
#include <random>
// #include "nlohmann/json.hpp"

namespace ec {
template <class DDType, class Config>
class PositionMatchApplicationScheme final
    : public ApplicationScheme<qc::MatrixDD, Config> {
public:
  PositionMatchApplicationScheme(
      TaskManager<qc::MatrixDD, Config>& taskManager1,
      TaskManager<qc::MatrixDD, Config>& taskManager2) noexcept
      : ApplicationScheme<qc::MatrixDD, Config>(taskManager1, taskManager2) {}

  void setInternalState(qc::MatrixDD& state) noexcept {
    internalState = &state;
  }
  void setPackage(dd::Package<Config>* dd) noexcept { package = dd; }


// void print(std::set<qc::Qubit> const &s)
// {
//     for (auto const &i: s) {
//         std::cout << unsigned(i) << " ";
//     }
//     std::cout << std::endl;
// }

  std::pair<size_t, size_t> operator()() override {
    assert(internalState != nullptr);
    assert(package != nullptr);

// print(subset1);
    subset1 = this->taskManager1.getUsedQubits();
    subset2 = this->taskManager2.getUsedQubits();

    auto       saved = *internalState;
    const auto dd1   = package->multiply(op1, saved);
    const auto size1 = package->size(dd1);
    const auto dd2   = package->multiply(saved, op2);

    // maxLoad = nqubit / 3;
    // maxLoad = std::max(std::max(subset1.size(), subset2.size()), activeQubits.size());
    maxLoad = std::max(subset1.size(), subset2.size());
    subset1.insert(activeQubits.begin(), activeQubits.end());
    subset2.insert(activeQubits.begin(), activeQubits.end());

    bool dirc = direction(subset1, subset2);
    if (dirc){
      if (subset1.size()>maxLoad){
        activeQubits = this->taskManager1.getUsedQubits();
      }
      else{
        activeQubits = subset1;
      }
      return {1U, 0U};
    } else {
      if (subset2.size()>maxLoad){
        activeQubits = this->taskManager2.getUsedQubits();
      }
      else{
        activeQubits = subset2;
      }
      return {0U, 1U};
    }

  }
bool direction(std::set<qc::Qubit> mergedSet1, std::set<qc::Qubit> mergedSet2){
    if (mergedSet1.size() == mergedSet2.size()) {
      // std::cout << cache;
      return randGen();
    } 


    // else if (mergedSet1.size() == mergedSet2.size() && mergedSet1.size() > size) {
    //   std::cout << "T";
    //   return true;
    // }
    // else if (mergedSet1.size() > size && mergedSet2.size()>size) {
    //   return false;
    // }
    // else {
      return mergedSet2.size() >= mergedSet1.size();
    // }
  }

  

private:
  [[nodiscard]] float computeGateRatio() const noexcept {
    const std::size_t size1 = this->taskManager1.getCircuit()->size();
    const std::size_t size2 = this->taskManager2.getCircuit()->size();
    return size1/(size1+size2);
  }
  std::set<qc::Qubit>  activeQubits{};
  // const std::size_t gateRatio;                                                               
  std::set<qc::Qubit>  subset1{};
  std::set<qc::Qubit>  subset2{};
  std::size_t maxLoad;
  bool cache = true;
  int cut = 0;

  // bool randGen(){
  //   float num = rand() % 128;
  //   if (num < 51) {
  //     return false;
  //   } else{
  //     return true;
  //   }
  // }
  bool randGen(){
    cut = cut+1;
    if (cut == 0){
    cache = !cache;
    }
    return cache;
  }

};
}