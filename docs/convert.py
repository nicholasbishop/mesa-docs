from glob import glob
from os import path
from subprocess import check_call

for input_name in glob('*.html'):
    output_name = path.splitext(input_name)[0] + '.rst'
    if not path.exists(output_name):
        cmd = ('pandoc', input_name, '-o', output_name)
        print ' '.join(cmd)
        check_call(cmd)
