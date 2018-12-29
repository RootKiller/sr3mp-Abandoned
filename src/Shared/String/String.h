//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

template <typename CHAR_TYPE = char, class ALLOCATOR = template DynamicHeapAllocator<CHAR_TYPE> >
class String
{
public:
	typedef ALLOCATOR		AllocatorType;
	typedef CHAR_TYPE		CharType;
private:
	CharType			*m_data;

	AllocatorType		m_allocator;
public:
	// Default constructor.
						String(void)
	{
		m_data = m_allocator.Alloc(1);
		m_data[0] = '\0';
	}

	// Copy constructor.
						String(const String &str)
	{
		*this = str;
	}

	// Move constructor.
						String(String &&str)
	{
		*this = str;
	}

	// C-String conversion constructor.
						String(const CharType *const str)
	{
		const unsigned stringLength = StrLen(str);
		m_data = m_allocator.Alloc(stringLength + 1);
		StrCpy(m_data, str);
		m_data[stringLength] = '\0';
	}

	//! Destructor.
						~String(void)
	{
		m_data = nullptr;
		m_allocator.Free();
	}

	//! Append string.
	void				Append(const CharType *const str)
	{
		// Make copy of current data.
		AllocatorType allocator;
		CharType *data = allocator.Alloc(m_allocator.GetSize());
		StrCpy(data, m_data);

		// Allocate new data
		const unsigned newSize = StrLen(m_data) + StrLen(str) + 1;
		m_data = m_allocator.Realloc(newSize);

		StrCpy(m_data, data);
		allocator.Free();

		StrCat(m_data, str);
	}

	//! Append string.
	String&			operator+(const CharType *const str)
	{
		Append(str);
		return *this;
	}

	//! Append number.
	String&			operator+(const unsigned number)
	{
		String strNumber;
		strNumber.Format("%u", number);
		Append(strNumber);
		return *this;
	}

	//! Append number.
	String&			operator+(const int number)
	{
		String strNumber;
		strNumber.Format("%d", number);
		Append(strNumber);
		return *this;
	}

	//! Append string.
	String&			operator+=(const CharType *const str)
	{
		Append(str);
		return *this;
	}

	//! Append number.
	String&			operator+(const float number)
	{
		String strNumber;
		strNumber.Format("%f", number);
		Append(strNumber);
		return *this;
	}

	//! Append number.
	String&			operator+(const double number)
	{
		String strNumber;
		strNumber.Format("%f", number);
		Append(strNumber);
		return *this;
	}

	// Find first string occurence.
	unsigned		FindFirst(const CharType *const str, const unsigned begin = 0)
	{
		ASSERT(begin < m_allocator.GetSize());
		unsigned index = Nil();

		const CharType *const ptr = StrStr(m_data + begin, str);
		if(ptr) {
			index = static_cast<unsigned>(ptr - m_data);
		}
		return index;
	}

	// Find last string occurence.
	unsigned		FindLast(const CharType *const str)
	{
		unsigned index =  Nil();
		do
		{
			const unsigned offset (IsNil(index) ? 0 : index);
			const CharType *ptr = StrStr(m_data + offset, str);
			if(ptr) {
				index = static_cast<unsigned>(ptr - m_data);
			}
		} while(ptr != NULL);

		return index;
	}

	// Find first character occurence.
	unsigned		FindFirst(const CharType c, const unsigned begin = 0)
	{
		ASSERT(begin < m_allocator.GetSize());
		unsigned index = Nil();

		const CharType *const ptr = StrChr(m_data + begin, c);
		if(ptr) {
			index = static_cast<unsigned>(ptr - m_data);
		}
		return index;
	}

	// Find last character occurence.
	unsigned		FindLast(const CharType c)
	{
		unsigned index = Nil();

		const CharType *const ptr = StrRChr(m_data, c);
		if(ptr) {
			index = static_cast<unsigned>(ptr - m_data);
		}
		return index;
	}

	// Sub string.
	void			SubStr(String& string, const unsigned start, const unsigned end = Nil())
	{
		ASSERT(start < end);
		ASSERT(start < m_allocator.GetSize());
		ASSERT(IsNil(end) || (end < m_allocator.GetSize()));

		if (IsNil(end)) {
			StrCpy(string.m_data, m_data + start);
		}
		else {
			StrNCpy(string.m_data, m_data + start, (end - start));
		}
	}

	// Cut string at.
	void			CutAt(const unsigned index)
	{
		ASSERT(index < m_allocator.GetSize());
		m_data[index] = static_cast<CharType>(0);
	}

	//! Get char at index.
	CharType		CharAt(const unsigned index) const
	{
		ASSERT(index < m_allocator.GetSize());
		return m_data[index];
	}

	//! Get char at index (variant allowing negative indexes).
	CharType		CharAt(const int index) const
	{
		unsigned finalIndex = Nil();

		if (index < 0) {
			finalIndex = static_cast<unsigned>(Length() + index);
		}
		else {
			finalIndex = static_cast<unsigned>(index);
		}

		ASSERT(NotNil(finalIndex) && (finalIndex < m_allocator.GetSize()));
		return m_data[finalIndex];
	}

	//! Get char at index.
	CharType		operator[](const unsigned index) const
	{
		return CharAt(index);
	}

	//! Get char at index (variant allowing negative indexes).
	CharType		operator[](const int index) const
	{
		return CharAt(index);
	}

	//! Get length of string.
	unsigned		Length(void) const
	{
		ASSERT(m_data);
		return StrLen(m_data);
	}

	//! Get number of bytes used by allocator.
	byte			GetBytes(void) const
	{
		return m_allocator.GetBytesSize();
	}

	//! Clear string content.
	void			Clear(void)
	{
		ASSERT(m_data);
		memset(m_data, 0, m_allocator.GetBytesSize());
	}

	//! Check if string is empty.
	bool			IsEmpty(void) const
	{
		ASSERT(m_data);
		return *m_data == 0;
	}

	//! Check if string is not empty.
	bool			NotEmpty(void) const
	{
		ASSERT(m_data);
		return *m_data != 0;
	}

	//! Check if string ends with string.
	bool			EndsWith(const CharType *const str) const
	{
		const unsigned strLen = StrLen(str);
		const unsigned len = Length();

		if (strLen > len) return false;

		return !StrCmp(m_data + (len - strLen), str);
	}

	//! Check if string ends with string.
	bool			StartsWith(const CharType *const str) const
	{
		const unsigned strLen = StrLen(str);
		const unsigned len = Length();

		if (strLen > len) return false;

		return !StrCmp(m_data, str);
	}

	/**
	 * Compares two strings.
	 *
	 * @param[in] str The string to compare.
	 * @return 0  in case strings are equal
	 *         -1 in case this is greater
	 *         1  in case str is greater
	 */
	int				Compare(const CharType *const str) const
	{
		return StrCmp(m_data, str);
	}

	//! Check if strings are equal.
	bool			Equals(const CharType *const str) const
	{
		return !StrCmp(m_data, str);
	}

	//! Check if two strings are equal.
	bool			operator==(const CharType *const str) const
	{
		return Equals(str);
	}

	//! Copy operator.
	String&			operator=(const String& rhs)
	{
		const unsigned stringLength = rhs.m_allocator.GetSize() - 1;
		m_data = m_allocator.Alloc(stringLength + 1);
		StrCpy(m_data, rhs.m_data);
		m_data[stringLength] = '\0';
		return *this;
	}

	//! Move operator.
	String&			operator=(String&& rhs)
	{
		const unsigned stringLength = str.m_allocator.GetSize() - 1;
		m_data = m_allocator.Alloc(stringLength + 1);
		StrCpy(m_data, str.m_data);
		m_data[stringLength] = '\0';
		rhs.Clear();
		return *this;
	}

	//! Get plain string representation.
	const CharType*		CStr(void) const		{ ASSERT(m_data); return m_data; }
	operator const CharType *(void) const		{ ASSERT(m_data); return m_data; }

	//! Format string.
	void Format(const CharType *const buffer, ...)
	{
		va_list args;
		va_start(args, buffer);
		const int desiredBufferSize = VSCPrintF(buffer, args);
		m_data = m_allocator.Realloc(desiredBufferSize + 1);
		SPrintF(m_data, buffer, args);
		m_data[desiredBufferSize] = '\0';
		va_end(args);
	}
};

//! Standard string to managed string add operator.
template <typename CHAR_TYPE, typename ALLOCATOR>
static String<CHAR_TYPE, ALLOCATOR> operator+(const CHAR_TYPE *const a, const String<CHAR_TYPE, ALLOCATOR>& b)
{
	String<CHAR_TYPE, ALLOCATOR> result(a);
	result.Append(b);
	return result;
}

//! Char type independent Fixed-size string
template <typename CHAR_TYPE, unsigned SIZE>
class FixedString : public String<CHAR_TYPE, FixedAllocator<CHAR_TYPE, SIZE> >
{
	using String::String;
};

//! ANSI Fixed-size string
template <unsigned SIZE>
class AFixedString : public String<char, FixedAllocator<char, SIZE> >
{
	using String::String;
};

//! WIDECHAR Fixed-size string
template <unsigned SIZE>
class WFixedString : public String<wchar_t, FixedAllocator<wchar_t, SIZE> >
{
	using String::String;
};

//! ANSI dynamic string
class AString : public String<char, DynamicHeapAllocator<char> >
{
	using String::String;
};

//! WIDECHAR dynamic string
class WString : public String<wchar_t, DynamicHeapAllocator<wchar_t> >
{
	using String::String;
};

/* EOF */
