/*
 * ContactsExporter.h
 *
 *  Created on: 27.08.2013
 *      Author: willy
 */

#ifndef CONTACTSEXPORTER_H_
#define CONTACTSEXPORTER_H_

#include "ContactsBase.h"

#include <QList>
#include <QString>
#include <QVariantList>

class ContactsExporter : public ContactsBase
{
	Q_OBJECT

public:
	enum Filetype {
		vCard,
		CSV
	};

	Q_ENUMS(Filetype);

	Q_PROPERTY(Filetype filetype READ filetype WRITE setFiletype NOTIFY filetypeChanged)

	Q_PROPERTY(QString filename READ filename WRITE setFilename NOTIFY filenameChanged)

	Q_PROPERTY(bool all READ all WRITE setAll NOTIFY allChanged)

	Q_PROPERTY(QVariantList contacts READ contacts WRITE setContacts NOTIFY contactsChanged)

	ContactsExporter();

	static void qmlRegisterType();

	Filetype filetype() const { return mFiletype; }
	void setFiletype(Filetype filetype);

	QString filename() const { return mFilename; }
	void setFilename(QString filename);

	bool all() const { return mAll; }
	void setAll(bool all);

	QVariantList contacts() const { return mContacts; }
	void setContacts(const QVariantList &contacts);

	Q_INVOKABLE void exportContacts(const QString &filename);

signals:
	void filetypeChanged(Filetype filetype);
	void filenameChanged(QString filename);
	void allChanged(bool all);
	void contactsChanged(const QVariantList &contacts);

private slots:
	void onContactsSelected(const QList<int> &contactList);

private:
	Filetype mFiletype;
	QString mFilename;
	bool mAll;
	QVariantList mContacts;
};

#endif /* CONTACTSEXPORTER_H_ */
