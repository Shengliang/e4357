
~/e4357/fall2015/ex1 (master) $ ./comp.sh 
arm-none-eabi-gcc: error: nano.specs: No such file or directory
arm-none-eabi-objcopy: 'fall2015_frdm_gpio.elf': No such file
arm-none-eabi-size: 'fall2015_frdm_gpio.elf': No such file

reference: https://launchpad.net/gcc-arm-embedded/+download
    1  ls
    6  ls -rtl
    7  git clone https://github.com/Shengliang/e4357.git
    8  sudo apt-get install gcc-arm-none-eabi
   18  ./comp.sh 
   23  \rm fall2015_frdm_gpio.bin fall2015_frdm_gpio.elf 
   29  cd bin
   30  wget https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q1-update/+download/gcc-arm-none-eabi-5_3-2016q1-20160330-linux.tar.bz2
   32  bunzip2 gcc-arm-none-eabi-5_3-2016q1-20160330-linux.tar.bz2
   35  tar -xvf gcc-arm-none-eabi-5_3-2016q1-20160330-linux.tar 
   39  find . -name arm-none-eabi-gcc
       export PATH=/home/ubuntu/e4357/bin/gcc-arm-none-eabi-5_3-2016q1/bin:$PATH
   41  vim ~/.bashrc
   42  bash
   44  history > a.txt

