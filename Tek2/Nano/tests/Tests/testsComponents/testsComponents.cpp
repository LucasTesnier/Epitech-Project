/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-lucas.tesnier
** File description:
** testsComponents
*/

#include <criterion/criterion.h>
#include <fstream>
#include "FileLoader/FileLoader.hpp"
#include "otherComponent/4001/C4001.hpp"
#include "otherComponent/4011/C4011.hpp"
#include "otherComponent/4030/C4030.hpp"
#include "otherComponent/4069/C4069.hpp"
#include "otherComponent/4071/C4071.hpp"
#include "otherComponent/4081/C4081.hpp"
#include "basicComponent/Clock/Clock.hpp"
#include "basicComponent/False/False.hpp"
#include "basicComponent/Input/Input.hpp"
#include "basicComponent/Output/Output.hpp"
#include "basicComponent/True/True.hpp"
#include "System/System.hpp"
#include "Error/Error.hpp"

// test C4001

class C4001Exposed : public nts::otherComponent::C4001 {
    public:
        using nts::otherComponent::C4001::calcNorGate;
};

Test(calcNorGate_isValid, check4001_true)
{
    C4001Exposed _c4001 = C4001Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4001.calcNorGate(pin1, pin2), true);
}

Test(calcNorGate_isValid, check4001_false)
{
    C4001Exposed _c4001 = C4001Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4001.calcNorGate(pin1, pin2), false);
}

Test(simulate, check4001_false)
{
    C4001Exposed _c4001 = C4001Exposed();

    _c4001.simulate(0);
}

Test(compute, check4001_false)
{
    C4001Exposed _c4001 = C4001Exposed();

    _c4001.compute(0);
}


























// test C4011

class C4011Exposed : public nts::otherComponent::C4011 {
    public:
        using nts::otherComponent::C4011::calcNandGate;
};

Test(calcNandGate_isValid, check4011_true1)
{
    C4011Exposed _c4011 = C4011Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4011.calcNandGate(pin1, pin2), true);
}

Test(calcNandGate_isValid, check4011_true2)
{
    C4011Exposed _c4011 = C4011Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4011.calcNandGate(pin1, pin2), true);
}

Test(calcNandGate_isValid, check4011_true3)
{
    C4011Exposed _c4011 = C4011Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4011.calcNandGate(pin1, pin2), true);
}

Test(calcNandGate_isValid, check4011_false)
{
    C4011Exposed _c4011 = C4011Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4011.calcNandGate(pin1, pin2), false);
}

Test(simulate, check4011_false)
{
    C4011Exposed _c4011 = C4011Exposed();

    _c4011.simulate(0);
}

Test(compute, check4011_false)
{
    C4011Exposed _c4011 = C4011Exposed();

    _c4011.compute(0);
}




















// test C4030

class C4030Exposed : public nts::otherComponent::C4030 {
    public:
        using nts::otherComponent::C4030::calcXorGate;
};

Test(calcXorGate_isValid1, check4030_true)
{
    C4030Exposed _c4030 = C4030Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4030.calcXorGate(pin1, pin2), true);
}

Test(calcXorGate_isValid2, check4030_true2)
{
    C4030Exposed _c4030 = C4030Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4030.calcXorGate(pin1, pin2), true);
}

Test(calcXorGate_isValid3, check4030_false2)
{
    C4030Exposed _c4030 = C4030Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4030.calcXorGate(pin1, pin2), false);
}

Test(calcXorGate_isValid4, check4030_false2)
{
    C4030Exposed _c4030 = C4030Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4030.calcXorGate(pin1, pin2), false);
}

Test(simulate, check4030_false)
{
    C4030Exposed _c4030 = C4030Exposed();

    _c4030.simulate(0);
}

Test(compute, check4030_false)
{
    C4030Exposed _c4030 = C4030Exposed();

    _c4030.compute(0);
}








// test C4069

class C4069Exposed : public nts::otherComponent::C4069 {
    public:
        using nts::otherComponent::C4069::calcNotGate;
};

Test(calcNotGate_isValid, check4069_true)
{
    C4069Exposed _c4069 = C4069Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    cr_assert_eq(_c4069.calcNotGate(pin1), true);
}

Test(calcNotGate_isValid, check4069_false)
{
    C4069Exposed _c4069 = C4069Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4069.calcNotGate(pin1), false);
}

Test(simulate, check4069_false)
{
    C4069Exposed _c4069 = C4069Exposed();

    _c4069.simulate(0);
}

Test(compute, check4069_false)
{
    C4069Exposed _c4069 = C4069Exposed();

    _c4069.compute(0);
}













// test C4071

class C4071Exposed : public nts::otherComponent::C4071 {
    public:
        using nts::otherComponent::C4071::calcOrGate;
};

Test(calcOrGate_isValid, check4071_true)
{
    C4071Exposed _c4071 = C4071Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4071.calcOrGate(pin1, pin2), true);
}

Test(calcOrGate_isValid, check4071_true2)
{
    C4071Exposed _c4071 = C4071Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4071.calcOrGate(pin1, pin2), true);
}

Test(calcOrGate_isValid, check4071_true3)
{
    C4071Exposed _c4071 = C4071Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4071.calcOrGate(pin1, pin2), true);
}

Test(calcOrGate_isValid, check4071_false)
{
    C4071Exposed _c4071 = C4071Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4071.calcOrGate(pin1, pin2), false);
}

Test(simulate, check4071_false)
{
    C4071Exposed _c4071 = C4071Exposed();

    _c4071.simulate(0);
}

Test(compute, check4071_false)
{
    C4071Exposed _c4071 = C4071Exposed();

    _c4071.compute(0);
}

















// test C4081

class C4081Exposed : public nts::otherComponent::C4081 {
    public:
        using nts::otherComponent::C4081::calcAndGate;
};

Test(calcAndGate_isValid, check4081_true)
{
    C4081Exposed _c4081 = C4081Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4081.calcAndGate(pin1, pin2), true);
}

Test(calcAndGate_isValid, check4081_false)
{
    C4081Exposed _c4081 = C4081Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4081.calcAndGate(pin1, pin2), false);
}

Test(calcAndGate_isValid, check4081_false2)
{
    C4081Exposed _c4081 = C4081Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4081.calcAndGate(pin1, pin2), false);
}

Test(calcAndGate_isValid, check4081_false3)
{
    C4081Exposed _c4081 = C4081Exposed();

    nts::pinInfo pin1 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    nts::pinInfo pin2 = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };

    cr_assert_eq(_c4081.calcAndGate(pin1, pin2), false);
}

Test(simulate, check4081_false)
{
    C4081Exposed _c4081 = C4081Exposed();

    _c4081.simulate(0);
}

Test(compute, check4081_false)
{
    C4081Exposed _c4081 = C4081Exposed();

    _c4081.compute(0);
}

// Clock

class ClockExposed : public nts::basicComponent::Clock {
};

Test(simulate, checkClock_false)
{
    ClockExposed _Clock = ClockExposed();

    _Clock.simulate(0);
}

Test(compute, checkClock_false)
{
    ClockExposed _Clock = ClockExposed();

    _Clock.compute(0);
}

Test(comingInput, checkClock_false)
{
    ClockExposed _Clock = ClockExposed();

    _Clock.getComingInput("1");
    _Clock.getComingInput("U");
    _Clock.getComingInput("0");
    _Clock.compute(0);
}

// False

class FalseExposed : public nts::basicComponent::False {
};

Test(simulate, checkFalse_false)
{
    FalseExposed _False = FalseExposed();

    _False.simulate(0);
}

Test(compute, checkFalse_false)
{
    FalseExposed _False = FalseExposed();

    _False.compute(0);
}

// Input

class InputExposed : public nts::basicComponent::Input {
};

Test(simulate, checkInput_Input)
{
    InputExposed _Input = InputExposed();

    _Input.simulate(0);
}

Test(compute, checkInput_Input)
{
    InputExposed _Input = InputExposed();

    _Input.compute(0);
}

Test(comingInput, checkInput_false)
{
    InputExposed _Input = InputExposed();

    _Input.getComingInput("1");
    _Input.getComingInput("0");
    _Input.getComingInput("U");
    _Input.compute(0);
}

// Output

class OutputExposed : public nts::basicComponent::Output {
};

Test(simulate, checkOutput_Output)
{
    OutputExposed _Output = OutputExposed();

    _Output.simulate(0);
}

Test(compute, checkOutput_Output)
{
    OutputExposed _Output = OutputExposed();

    _Output.compute(0);
}

// True

class TrueExposed : public nts::basicComponent::True {
};

Test(simulate, checkTrue_True)
{
    TrueExposed _True = TrueExposed();

    _True.simulate(0);
}

Test(compute, checkTrue_True)
{
    TrueExposed _True = TrueExposed();

    _True.compute(0);
}

Test(dump, checkTrue_True)
{
    TrueExposed _True = TrueExposed();

    _True.dump();
}

Test(changeState, checkTrue_True)
{
    TrueExposed _True = TrueExposed();

    _True.changePinState(0, nts::Tristate::TRUE);
}

Test(getName, checkTrue_True)
{
    TrueExposed _True = TrueExposed();

    cr_assert_eq(_True.getName(), "True");
}

Test(getComingInput, checkTrue_True)
{
    TrueExposed _True = TrueExposed();

    _True.getComingInput("1");
}