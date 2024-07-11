//
// This file is part of the MQT QCEC library released under the MIT license.
// See README.md or go to https://github.com/cda-tum/qcec for more information.
//

#include "EquivalenceCheckingManager.hpp"
#include "gtest/gtest.h"
#include <functional>
#include <iostream>
#include <random>
#include <string>


class JournalTestEQ : public testing::TestWithParam<std::string> {
protected:
  qc::QuantumComputation qcOriginal;
  qc::QuantumComputation qcTranspiled;
  ec::Configuration      config{};

  std::string testOriginalDir   = "./test/circuits/original/";
  std::string testTranspiledDir = "./test/circuits/transpiled/";


  // std::string testOriginalDir   = "./test/circuits/NewBench/";
  // std::string testTranspiledDir = "./test/circuits/NewBench/";

  std::string transpiledFile{};

  void SetUp() override {
    using namespace std::chrono_literals;

    config.execution.parallel               = false;
    config.execution.runConstructionChecker = false;
    config.execution.runAlternatingChecker  = false;
    config.execution.runZXChecker           = false;
    config.execution.runSimulationChecker   = false;
    config.simulation.maxSims               = 16;
    config.application.simulationScheme = ec::ApplicationSchemeType::PositionMatch;
    config.execution.timeout            = 60s;

    std::stringstream ss{};
    ss << testTranspiledDir << GetParam() << "_transpiled.qasm";
    transpiledFile = ss.str();

    qcOriginal.import(testOriginalDir + GetParam() + ".real");
    qcTranspiled.import(transpiledFile);


  //   std::stringstream ss{};
  //   ss << testTranspiledDir << GetParam() << "/" << GetParam() << "_transpiled.qasm";
  //   transpiledFile = ss.str();

  //   qcOriginal.import(testOriginalDir + GetParam() + "/" + GetParam() + ".qasm");
  //   qcTranspiled.import(transpiledFile);
  }
};

INSTANTIATE_TEST_SUITE_P(
    Journal, JournalTestEQ,
    testing::Values(
                    "dk27_225",
                    "pcler8_248",
                    "5xp1_194",
                    "alu1_198",
                    "mlp4_245",
                    "dk17_224",
                    "add6_196",
                    "C7552_205",
                    "cu_219",
                    "example2_231",
                    "c2_181",
                    "rd73_312",
                    "cm150a_210",
                    "cm163a_213",
                    "c2_182",
                    "sym9_317",
                    "mod5adder_306",
                    "rd84_313",
                    "cm151a_211",
                    "apla_203"
                    ),


    // testing::Values(
    //                 "adder_n28",
    //                 "adder_n64",
    //                 "adder_n118",
    //                "cat_state_n22",
    //                "ghz_state_n23",
    //                "ising_n26",
    //                "multiplier_n15",
    //                "multiply_n13",
    //                "multiplier_n45",
    //                "qec9xz_n17",
    //                "qf21_n15",
    //                "qft_n18",
    //                "qram_n20",
    //                "sat_n11"
    //               ),
    [](const testing::TestParamInfo<JournalTestEQ::ParamType>& info) {
      std::string name = info.param;
      std::replace(name.begin(), name.end(), '-', '_');
      std::stringstream ss{};
      ss << name;
      return ss.str();
    });



TEST_P(JournalTestEQ, EQPositionMatch) {
  config.execution.parallel              = false;
  config.execution.runAlternatingChecker = true;
  config.application.alternatingScheme   = ec::ApplicationSchemeType::PositionMatch;

  ec::EquivalenceCheckingManager ecm(qcOriginal, qcTranspiled, config);
  ecm.run();

  // config.application.alternatingScheme   = ec::ApplicationSchemeType::Proportional;
  // ec::EquivalenceCheckingManager ecm2(qcOriginal, qcTranspiled, config);
  // ecm2.run();

  EXPECT_TRUE(ecm.getResults().consideredEquivalent());
}

// TEST_P(JournalTestEQ, EQProportional) {
//   config.execution.parallel              = true;
//   config.execution.runAlternatingChecker = true;
//   config.application.alternatingScheme   = ec::ApplicationSchemeType::Proportional;

//   ec::EquivalenceCheckingManager ecm(qcOriginal, qcTranspiled, config);
//   ecm.run();
//   EXPECT_TRUE(ecm.getResults().consideredEquivalent());
// }