# rb_import [![Build Status](https://travis-ci.org/franckverrot/rb_import.svg?branch=master)](https://travis-ci.org/franckverrot/rb_import)

`rb_import` adds an `import` method to your Ruby VM that lets you
load a file that exposes a Ruby object. As long as the imported file
doesn't pollute the VM's constants table (ie: defines a constant),
the caller won't see any unwanted objects.

## RATIONALE

`require`-ing/`load`-ing a file in Ruby works by assigning constructs
(classes, modules, functions, etc.) to constants, so that they could be
reused in other parts of your app.

The problem is: a library that you don't own can use any name for any
of its construct that could potentially collide with your own app's
construct names. Naming is hard and, namespacing with modules doesn't
even work (colliding module names, crazy meta-programming, etc.).

With `rb_import`, simply return a Ruby object from your files and
`import` them only in classes that will need those objects.


## INSTALLATION

Add this line to your application's Gemfile:

    gem 'rb_import'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install rb_import

Alternatively, you can spawn a `pry` console right away by just running:

    $ rake console

## USAGE

```ruby
# foo.rb
Class.new do
  def bar
    "bar"
  end
end

# bar.rb
foo = import './foo.rb'
puts foo.new.bar # => outputs "bar"
```

See files in the `test` directory for examples.

## Is it any good?

[Yes](http://news.ycombinator.com/item?id=3067434).

## Is It "Production Ready™"?

Yes. I guess.

## Contributing

1. Fork it ( https://github.com/franckverrot/rb_import/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
