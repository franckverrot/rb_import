Class.new do
  @@bar = import './test/fixtures/bar.rb'
  def to_s
    "foo #{@@bar.new.bar}"
  end
end
