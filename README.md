![](TinyWeb_logo.png)


----------------

TinyWeb is a high-performance web server which is based on C++11.

- TinyWeb utilizes what's called an event-driven programming model.
- The implementation method is epoll+no-blocking I/O.
- The gobals of this application are high-performance,stability,simple configuration,
and low resource consumption.
- Module design is a efficient approach to design this system.

---------------------

## Quick Start

### Get Code
```
git clone https://github.com/GeneralSandman/TinyWeb
```

### Install
```
cd TinyWeb/src
mkdir build
cd build
cmake ../ && make
```

### Configure
```
sudo cp TinyWeb.conf /
vim /TinyWeb.conf
```

```config file：```
There are two parts in config-file, ```develop``` and ```product```. Those have same formate. One for debug, another for product eventment.

```
{
    "develop": {

        "basic": {
            "worker": 2,
            "pid": "/var/run/TinyWeb.pid",
            "sendfile": true,
            "mimetype": "mime.types",
            "chunked": true,
            "gzip": true,
            "gzip_level" : 2,
            "gzip_buffers_4k" : 4,
            "gzip_min_len": 1024,
            "gzip_http_version": ["1.0", "1.1"],
            "gzip_mime_type": ["text/html", "text/css"]
        },

        "server": [
            {
                "listen": 9090,
                "servername": [
                    "127.0.0.1",
                    "www.dissigil.cn"
                ],
                "www": "/home/dell/TinyWeb/www",
                "indexpage": [
                    "index.html",
                    "index.htm",
                    "index.php"
                ],
                "errorpage": [
                    {
                        "code" : [404],
                        "path" : "/home/dell/TinyWeb/www",
                        "file" : "404.html"
                    },
                    {
                        "code" : [500,502,503,504],
                        "path" : "/home/dell/TinyWeb/www",
                        "file" : "50x.html"
                    }
                ]
            }
        ],

        "log": {
            "level": "Debug",
            "path": "/home/dell/TinyWeb/log",
            "debugfile": "debug.log",
            "infofile": "info.log",
            "warnfile": "warn.log",
            "errorfile": "error.log",
            "fatalfile": "fatal.log"
        }
    }
}

```


### Start Server

- Start server with default file ```/TinyWeb.conf```.You need to create this file if it does not exist otherwise server return error and exit.

```
sudo ./TinyWeb
```

- A configure file will be appointed when using ```-c <file>```.

```
sudo ./TinyWeb -c /home/li/TinyWeb.conf
```

- Start server with Debug level and ignore the level of configure file.(Server is under terminal's control because It is not a daemon process)

```
sudo ./TinyWeb -d -c /home/li/TinyWeb.conf
```

- Stop server safely
```
sudo ./TinyWeb -o stop

cat /var/run/TinyWeb.pid
sudo kill -s SIGQUIT <master-pid> 
```

- Stop server immeditely
```
sudo ./TinyWeb -o stop

cat /var/run/TinyWeb.pid
sudo kill -s SIGTERM <master-pid> 
sudo kill -s SIGINT <master-pid> 
```

- Restart server
```
sudo ./TinyWeb -o restart

cat /var/run/TinyWeb.pid
sudo kill -s SIGUSR1 <master-pid> 
```

- Reload server with new configure file
```
sudo ./TinyWeb -o reload [-c <config-file>]

cat /var/run/TinyWeb.pid
sudo kill -s SIGUSR2 <master-pid> 
```

- Test configure file is vliad or not
```
sudo ./TinyWeb --tcf /path/path/configfile
```

- Get version
```
sudo ./TinyWeb -v
```

---------------------

## Guide
[TinyWeb Guides](http://www.dissigil.cn/TinyWeb-0/)


--------------

## Develop Idea & Challenge & Plan
[Idea](http://github.com/GeneralSandman/docs/Idea.md)

---------------

## 


## Reference：

1.[Advanced Programming in the Unix Environment](https://en.wikipedia.org/wiki/Advanced_Programming_in_the_Unix_Environment)

2.[UNIX Network Programming](https://en.wikipedia.org/wiki/UNIX_Network_Programming)

3.C++ Primer

5.[Linux 多线程服务端编程：使用 muduo C++ 网络库](https://github.com/chenshuo/documents)

6.[C++ Reference](http://en.cppreference.com/w/cpp)

7.[高性能服务器编程](http://blog.csdn.net/column/details/high-perf-network.html)
