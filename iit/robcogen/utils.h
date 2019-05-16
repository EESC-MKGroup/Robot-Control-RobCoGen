/* CPYHDR { */
/*
 * This file is part of the 'iit-rbd' library.
 * Copyright © 2015-2018, Marco Frigerio
 *
 * See the LICENSE file for more information.
 */
/* } CPYHDR */

#ifndef IIT_ROBCOGEN_UTILS_H_
#define IIT_ROBCOGEN_UTILS_H_

#include <iostream>
#include <ctime>

#include <iit/rbd/rbd.h>

namespace iit {
/**
 * This namespace contains some facilities related to the C++ code generated by
 * the Robotics Code Generator (RobCoGen).
 *
 * Nothing in this namespace is required to *compile* nor to *use* the
 * kinematics/dynamics engines generated by RobCoGen in one's application.
 * Think of this namespace as a container for bonus material, such as functions
 * to test the generated C++.
 */
namespace robcogen {

/**
 * Utilities to be used with the C++ code generated by RobCoGen
 */
namespace utils {


template <class RT>
void cmdlineargs_jstate(int argc, char** argv, typename RT::JointState& state)
{
    if(argc < RT::joints_count) {
        std::cerr << "Not enough arguments" << std::endl;
        exit(-1);
    }
    for(int i=0; i<RT::joints_count; i++) {
        state(i) = std::atof(argv[i]);
    }
}

template <class RT>
void cmdlineargs_jstate(int argc, char** argv,
        typename RT::JointState& state1,
        typename RT::JointState& state2)
{
    if(argc < 2*RT::joints_count) {
        std::cerr << "Not enough arguments" << std::endl;
        exit(-1);
    }
    for(int i=0; i<RT::joints_count; i++) {
        state1(i) = std::atof(argv[i]);
        state2(i) = std::atof(argv[RT::joints_count+i]);
    }
}

template <class RT>
void cmdlineargs_jstate(int argc, char** argv,
        typename RT::JointState& state1,
        typename RT::JointState& state2,
        typename RT::JointState& state3)
{
    if(argc < 3*RT::joints_count) {
        std::cerr << "Not enough arguments" << std::endl;
        exit(-1);
    }
    for(int i=0; i<RT::joints_count; i++) {
        state1(i) = std::atof(argv[i]);
        state2(i) = std::atof(argv[i+RT::joints_count]);
        state3(i) = std::atof(argv[i+2*RT::joints_count]);
    }
}


template <class RT>
void rand_jstate(typename RT::JointState& state)
{
    std::srand(std::time(NULL));
    for(int i=0; i<RT::joints_count; i++) {
        state(i) = ((double)std::rand()) / RAND_MAX;
    }
}

/**
 * Random initialization of three joint-status vectors.
 * \tparam RT the Traits class of the robot, as generated by RobCoGen
 */
template <class RT>
void rand_jstate(
    typename RT::JointState& q,
    typename RT::JointState& qd,
    typename RT::JointState& qdd)
{
    std::srand(std::time(NULL));
    for(int i=0; i<RT::joints_count; i++) {
        q(i)   = ((double)std::rand()) / RAND_MAX;
        qd(i)  = ((double)std::rand()) / RAND_MAX;
        qdd(i) = ((double)std::rand()) / RAND_MAX;
    }
}



}
}
}

#endif
