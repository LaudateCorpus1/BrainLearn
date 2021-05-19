﻿#ifndef _EVALUATE_NNUE_LEARNER_H_
#define _EVALUATE_NNUE_LEARNER_H_

#include "learn/learn.h"

#include "misc.h"

struct ThreadPool;

// Interface used for learning NNUE evaluation function
namespace Stockfish::Eval::NNUE {

    // Initialize learning
    void initialize_training(
        const std::string& seed,
        SynchronizedRegionLogger::Region& out);

    // set the number of samples in the mini-batch
    void set_batch_size(uint64_t size);

    // Set options such as hyperparameters
    void set_options(const std::string& options);

    // Reread the evaluation function parameters for learning from the file
    void restore_parameters(const std::string& dir_name);

    // Add 1 sample of learning data
    void add_example(
        Position& pos,
        Color rootColor,
        Value discrete_nn_eval,
    	const Learner::PackedSfenValue& psv,
        double weight);

    // update the evaluation function parameters
    Learner::Loss update_parameters(
        ThreadPool& thread_pool,
        uint64_t epoch,
        bool verbose,
        double learning_rate,
        double max_grad,
        Learner::CalcLossFunc calc_loss);

    // Check if there are any problems with learning
    void check_health();

    void finalize_net();

    void save_eval(std::string suffix);
}  // namespace Stockfish::Eval::NNUE

#endif
