#define Q_PROPERTY_FULL(member, _type) \
  Q_PROPERTY(_type member READ member WRITE set##member NOTIFY member##Changed) \
  public: \
    void set##member##(_type _arg_##member) { if (m_##member != _arg_##member) {m_##member = _arg_##member; Q_EMIT member##Changed();  } } \
    _type member##() const { return m_##member; } \
  Q_SIGNALS: \
    void member##Changed(void); \
  private: \
    _type m_##member;