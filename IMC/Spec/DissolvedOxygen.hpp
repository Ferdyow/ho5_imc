//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 2a5f30dbbf2c8bf48b108c920bd86353                            *
//***************************************************************************

#ifndef IMC_DISSOLVEDOXYGEN_HPP_INCLUDED_
#define IMC_DISSOLVEDOXYGEN_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>

namespace IMC
{
  //! Dissolved Oxygen.
  class DissolvedOxygen: public Message
  {
  public:
    //! Value.
    float value;

    static uint16_t
    getIdStatic(void)
    {
      return 295;
    }

    static DissolvedOxygen*
    cast(Message* msg__)
    {
      return (DissolvedOxygen*)msg__;
    }

    DissolvedOxygen(void)
    {
      m_header.mgid = DissolvedOxygen::getIdStatic();
      clear();
    }

    DissolvedOxygen*
    clone(void) const
    {
      return new DissolvedOxygen(*this);
    }

    void
    clear(void)
    {
      value = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::DissolvedOxygen& other__ = static_cast<const DissolvedOxygen&>(msg__);
      if (value != other__.value) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(value, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return DissolvedOxygen::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "DissolvedOxygen";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 4;
    }

    double
    getValueFP(void) const
    {
      return static_cast<double>(value);
    }

    void
    setValueFP(double val)
    {
      value = static_cast<float>(val);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "value", value, nindent__);
    }
  };
}

#endif