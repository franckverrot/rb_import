# coding: utf-8
$:<< 'lib'

Gem::Specification.new do |spec|
  spec.name          = "rb_import"
  spec.version       = "0.1.0"
  spec.authors       = ["Franck Verrot"]
  spec.email         = ["franck@verrot.fr"]
  spec.summary       = %q{Add an import method to your Ruby VM}
  spec.description   = spec.summary
  spec.homepage      = "https://github.com/franckverrot/rb_import"
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]
  spec.extensions   << 'ext/rb_import/extconf.rb'

  spec.add_development_dependency "bundler", "~> 1.5"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "pry"
  spec.add_development_dependency "minitest"
end
