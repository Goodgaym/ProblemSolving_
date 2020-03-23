#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) {
    // ����� �����ϴ� ���. �ش� ����� future �� ����.
    p->set_value("some data");
}
int main() {
    std::promise<string> p;

    // �̷��� string �����͸� ���� �ְڴٴ� ���.
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    // �̷��� ��ӵ� �����͸� ���� �� ���� ��ٸ���.
    data.wait();

    // wait �� �����ߴٴ� ���� future �� �����Ͱ� �غ�Ǿ��ٴ� �ǹ�.
    // ����� wait ���� �׳� get �ص� wait �� �Ͱ� ����.
    std::cout << "���� ������ : " << data.get() << std::endl;

    t.join();
}

